// https://zerojudge.tw/ShowProblem?problemid=f161
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll K, Ans = 0, tmpAns;
int M,N, food;
// int G[55][300005] = {0}; //前綴和矩陣 segmention fault 太大了!!
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> K >> M >> N;
    vector< vector <ll> > G(M+1, vector <ll>(N+1) );//前綴和矩陣 int G[M+1][N+1];
    // also can
    // int G[M+1][N+1];

    //init (不做也可以)
    for (int i=0; i<=M; i++) G[i][0] = 0;
    for (int i=0; i<=N; i++) G[0][i] = 0;
    
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            cin >> food;
            G[i][j] = food + G[i-1][j] + G[i][j-1] - G[i-1][j-1]; // Calc prefix
        
            // 計算當前小等於K的最大值
            for (int x=0; x<i; x++) {
                for (int y=0; y<j; y++) {
                    tmpAns = G[i][j] - G[x][j] - G[i][y] +  G[x][y];
                    if (tmpAns <= K && tmpAns > Ans ) Ans = tmpAns;
                }
            }
        }
    }
    cout << Ans << endl;
    return 0;
}