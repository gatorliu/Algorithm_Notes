// https://zerojudge.tw/ShowProblem?problemid=d682
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

#define f first
#define s second

/* DP: 0.7s 有更快的方法 see:
    https://github.com/cthbst/ACM/blob/master/zerojudge/d682.cpp
*/

int M, N, P;
map<int, int> dp[55][55];
vector< vector< pair<int, int> > >G;
//pair<int, int> G[55][55];

int solve(int m, int n, int p) { 
    //cout << "(n,m) = ("  << n << ", " << p << endl;
    if (n == N || p == P) return 0;

    auto  it =  dp[n][p].find(m);
    if ( it != dp[n][p].end() ) return (*it).s;

    int mx=0;
    pair <int,int> pp = G[n][p];
    if( m - pp.f >= 0)
        mx = max(mx, solve(m-pp.f, n+1, 0 ) + pp.s);  // 選這個
    
    mx = max(mx, solve(m, n, p+1 ));  // 不選這個，去下一個
    
    if (p == 0)
        mx = max ( mx,  solve(m, n+1, 0) ); // 不選這個，去下一行

    // if (p > 0)  dp[m][n][p] = mx;
    dp[n][p].insert({m,mx});
    return mx;
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> M >> N >> P;
    G = vector< vector<pair<int, int> > >( N, vector<pair<int, int>>(P,{0,0}));

    for (auto &n: G) {
        for (auto &p: n) {
            cin >> p.f >> p.s;
        }
        /*
        sort(n.begin(), n.end(), [](pair<int, int>a, pair<int, int>b){
            if (a.f == b.f) return a.s > b.s;
            else return a.f < b.f;
        });
        */
    }
    cout << solve(M, 0, 0) << endl;

    return 0;
}