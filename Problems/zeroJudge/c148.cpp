// https://zerojudge.tw/ShowProblem?problemid=c148
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>


typedef long long ll;
#define key first
#define value second
using namespace std;

int N, M ;
int S, E, K;
bool MP[1001][1001];
int DP[1001][1001][3];

int ans;

//dfs
void solve(int r, int c, int way /* way = 0 down, 1 right, 2 left */, int turns){
    if (r == N-1 && c == E) { //終點
        if (turns < ans) ans = turns;
        return;
    }
    if ( DP[r][c][way] <= turns ) {
        return;
    } else {
        DP[r][c][way] = turns;
    }

    //cout << "r=" << r << " c=" << c << " way=" << way << " t=" << turns << endl;
    if (way == 0) { //可以往下，或左右
        if ( r+1<N  &&  MP[r+1][c]==0) solve(r+1, c, 0, turns); // down
        if ( c+1<M  &&  MP[r][c+1]==0) solve(r, c+1, 1, turns+1); // right
        if ( c>0    &&  MP[r][c-1]==0) solve(r, c-1, 2, turns+1); // left
    } else { // only 下 或同方向
        if ( r+1<N  &&  MP[r+1][c]==0) solve(r+1, c, 0, turns+1); // down
        if      ( way == 1 && c+1<M  &&  MP[r][c+1]==0) solve(r, c+1, 1, turns); // right
        else if ( way == 2 && c>0    &&  MP[r][c-1]==0) solve(r, c-1, 2, turns); // left
    }
    return;

}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin >> N >> M) {
        for (int n=0; n<N; n++)for (int m=0; m<M; m++) {MP[n][m]= 0; DP[n][m][0]=3*N; DP[n][m][1]=3*N; DP[n][m][2]=3*N; }  // init
        int r, c;
        cin >> S >> E >> K;
        while(K--) {
            cin  >> r >> c;
            MP[r][c] = 1;
        }
        ans = 3*N;
        solve(0, S, 0, 0);
        cout << ans << endl;
    }   
    return 0;
}