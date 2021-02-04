// https://zerojudge.tw/ShowProblem?problemid=b351
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5005;

int main() {
    

    int t, N, R, C;
    cin >> t;
    while(t--) {
        //int Mat[MAX][MAX] = {0};
        cin >> N >> R >> C;
        vector< vector <bool> > Mat(N+2, vector <bool> (N+2, false));
        
        int x=1, y= (N+1)/2 ;
        int tx,ty;
        int n = 1;
        //cout << x << ", " << y << ", " << n << endl;
        int NN= N*N;
        while(n<=NN) {
            Mat[x][y] = true;
            //cout << x << ", " << y << ", " << n << endl;
            if (x==R && y==C) {
                cout << n<< endl;
                break;
            }
            
            tx= x- 1;ty=y- 1;
            if( tx < 1) tx=N;
            if( ty < 1) ty=N;
            if (Mat[tx][ty]){
                tx = x + 1;
                ty = y;
                if (tx>N) tx=1;
            }
            n++; x=tx; y=ty;
        }
    }
    return 0;
}