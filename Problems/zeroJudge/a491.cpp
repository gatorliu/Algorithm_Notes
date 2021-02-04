// https://zerojudge.tw/ShowProblem?problemid=a491
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll; 

const int MAX = 2005;
int mv[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int used[MAX][MAX]={0};
int R,C;

struct data {
    int r; int c; int v;
};
void putq(queue< pair<int, int> > &Q, int r, int c ) {
    for (int i =0; i <4; i++) {
        int x = r + mv[i][0];
        int y = r + mv[i][1];
        //cout << x << " " << y << " " <<  used[x][y] << endl;
        if (x >=0 && x < R && y >=0 && y<C && used[x][y]==0) {
            used[x][y] = 1;
            Q.push({x,y});
            //cout << "Size: " << Q.size()<< endl;
        }

    }
}
ll getVal( vector<data> vec, int r, int c ) {
    ll val=0;
    for (auto v : vec){
        val += v.v * (
            ((v.r > r) ? (v.r-r) : (r-v.r) )+ 
            ((v.c > c) ? (v.c-c) : (c-v.c) ) ); 
    }
    return val*100;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        vector<data> vec;

        cin >> R >> C;
        int mx_v=0, tmp_r=0, tmp_c=0;
        int val;
        
        for (int i=0;i<R;i++) for (int j=0;j<C;j++) used[i][j]=0;        
        
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                cin >> val;
                if (val) vec.push_back({i,j, val});
                if (val > mx_v) {
                    mx_v =  val; tmp_r = i; tmp_c=j;
                }
            }
        }
        //cout << "input down" << endl;
        queue< pair<int, int> > Q;
        ll ans = 1e16;
        Q.push({tmp_r, tmp_c});
        used[tmp_r][tmp_c] = 1;     
        while(Q.size()>0){
            //cout << "Q" << endl; cout <<Q.size() << endl;
            pair<int, int> p =  Q.front(); Q.pop();
            
            val =  getVal(vec, p.first, p.second);
            if (val <= ans) {
                ans = val;
                if ( val == ans  && (tmp_r > p.first || (tmp_r == p.first && tmp_c > p.second )) ) { 
                    tmp_r = p.first;
                    tmp_c = p.second;
                } else {
                    tmp_r = p.first;
                    tmp_c = p.second;
                }
                putq(Q, p.first, p.second);
            }
            //cout <<Q.size() << endl;
        } 
        cout << tmp_r+1 << " " << tmp_c+1 << "\n" << ans << endl;
    }
}