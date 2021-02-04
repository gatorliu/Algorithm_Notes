// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
#define t first
#define w second

vector<pair<int,int> > MP[100000+5];
ll dp[100000+5]={0};
const ll MAX_N = 9223372036854775807; // (1<<63)-1
int N, M;

void dfs(int town, ll weight) {
    if(dp[town] > weight ) {
        dp[town] = weight;
    } else {return ;}
    //if (MP[town].size()==0) return;
    
    for (auto t: MP[town]) {
        //cout << "call dfs( " <<t.t << "," << weight+t.w << endl;
        dfs(t.t, weight+t.w);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;
    int u, v, w;
    // input
    for(int i=0; i<M ;i++ ) {
        cin >> u >> v >> w;
        MP[u].push_back({v,w});
    }
    /* debug
    for(int i=0; i<N ;i++ ) {
        cout << i << " :";
        for (auto c : MP[i]) cout << c.t << "," << c.w <<"; ";
        cout << endl;
    }
    */
    // init 
    for(int i=1; i<=N; i++)  dp[i]=MAX_N; // (1<< 63)- 1
    // solve
    dfs(1,0);

    ll sum =0;
    // cout << "-----------" << endl;
    for(int i=2; i<=N; i++) {
        // cout << dp[i] << endl;
        sum += dp[i];
    }
    // cout << endl;

    cout << sum <<endl;

    return 0;
}