// https://zerojudge.tw/ShowProblem?problemid=f428
// https://zerojudge.tw/ShowProblem?problemid=f432
// 輸入x,y 會超出範圍 
#include <iostream>
#include <vector>

using namespace std;
const int Nmax = 1e9+5;
vector<long long> quarterdp; 

int abs (int n ) { if (n<0) return -n; else return n;}

void init (int n) {
    quarterdp.push_back(0);
    quarterdp.push_back(1);
    for(int i=2; i<=n; i++) {
        quarterdp.push_back(quarterdp[i-1] + i*(i*2-1));
        //cout << quarterdp[i] << endl;
    }
}

long long quarter_ans ( int x1, int x2, int y1, int y2) {
    int mx =  max(x2, y2);
    int s_mx =  max(x1, y1) - 1;
    int s_mn =  min(x1, y1)-1;
    long long ans = quarterdp[mx];
    // 全部 - 3個區塊 ()
    /*
    cout << mx  << " " << ans << endl;
    cout << s_mx << endl;
    cout << quarterdp[s_mx] << endl;
    cout << ( s_mx * (mx + s_mx+1)*(mx - s_mx)/2 ) << endl;
    cout << ( s_mn * (mx + s_mx+1)*(mx - s_mx)/2 ) << endl;
    */
    ans -=  quarterdp[s_mx];
    ans -=  ( s_mx * (mx + s_mx+1)*(mx - s_mx)/2 );
    ans -=  ( s_mn * (mx + s_mx+1)*(mx - s_mx)/2 );
    return ans;
        
}


int main() {

    /*
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (x2 < x1) swap(x1, x2);
    if (y2 < y1) swap(y1, y2);
    */
    //cout << ;
    init( max(max(abs(x1-n), abs(x2-n)), max (abs(y1-n), abs(y2-n)))  + 1 );
    
    // 未完成!!
    long  long ans = quarter_ans();
    /*
    long long ans = 1;
    int cell = 1;
    for (int ring = 2; ring <=n; ring++) {
        cell = (ring*2 -1)*(ring*2 -1) -  cell;
        ans += cell * ring;  // 計算所有的總和
        ans -=();
    }
    */

    /*
    int x, y;
    for (int i=max(x1,1); i<=min(x2,2*n-1); i++) {
        x = (i > n )? i-n : n-i  ;
        for (int j=min(y1, 2*n-1); j>=max(y2,1); j--){
            y = (j > n ) ? j-n : n-j ;
            ans += max( x, y ) + 1;
        }
    }
    */
    cout << ans << endl;
}