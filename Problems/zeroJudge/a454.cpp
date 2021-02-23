// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>


using namespace std;
typedef long long ll;

vector<ll> dp;

ll dfs( ll WD[],  vector <int> G[], int city) {
    //cout << '\t' << city <<  endl ;
    if(dp[city] > -1) return dp[city];
    if (G[city].empty()) {
        dp[city] = WD[city];
        return dp[city];
    }
    ll mx=0, tmp;
    for(auto c : G[city]) {
        tmp = dfs(WD, G, c) + WD[city];
        if (tmp > mx) mx = tmp;
    }
    dp[city] = mx;
    return mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N, k, p;
    ll w;
    cin >> M;
    while(M--) {
        cin >> N;
        ll WD[N+1]; // working day (input)
        //dp.clear(); dp.resize(N+1);
        dp = vector<ll>(N+1, -1);
        vector<int> G[N+1]; // Graph
        int PRE[N+1]; // 先前作業記數
        for(int i=1; i<=N; i++) PRE[i]=0;

        for(int i=1; i<=N; i++) {
            cin >> WD[i];
            cin >> k;
            G[i] = vector<int>(k);
            for(auto &g: G[i]) {
                cin >> g;
                PRE[g]++;
            }
        } 
        
        // solve
        ll mx=0;
        ll tmp;
        for(int i=1; i<=N; i++) {
            if (PRE[i] == 0) { 
                tmp = dfs(WD, G, i);
                if (tmp> mx) mx = tmp;
            }
        }
        cout << mx << endl;
    }

    return 0;
}