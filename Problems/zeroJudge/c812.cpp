// https://zerojudge.tw/ShowProblem?problemid=c182
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector< vector<int> > vii;    // init:   V = vii(3, vi(5,0));
typedef pair<int, int> pii;
 
#define PB push_back
#define F first 
#define S second 
 
int n, V, q; 
vector< vector< pii > >G;
vi used;
int solve(int v, int q, int cnt) {
    used[v] = 1;
    for (auto v2 : G[v]) {
        if (used[v2.F] == 0 && v2.S>=q) {
            cnt = solve(v2.F, q, cnt+1);
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> V >> q;
    V--;
    G = vector< vector< pii > >(n, vector< pii >());
    used = vi(n, 0);
    
    // input
    while(n-->1) {
       int v1, v2, r; cin >> v1 >> v2 >> r;
       v1--; v2--;
       G[v1].push_back({v2,r});
       G[v2].push_back({v1,r});
    }

    cout << solve(V, q, 0) << endl;
    return 0;
 
}