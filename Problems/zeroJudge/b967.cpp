// https://zerojudge.tw/ShowProblem?problemid=967
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef vector< vector <int> > vvi;
typedef vector<int> vi;
typedef long long ll;


int N;
vvi FTree;
vi Depth;
int MX=0;

void solve(int parent) {
    vi childs = FTree[parent];
    for (auto child : childs ) {
        solve(child);
        MX = max(MX, Depth[parent] + Depth[child]+1 ); // 之前的 parent 距離+  新的 child 
        Depth[parent] =  max( Depth[parent], Depth[child]+1 );
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    while (cin >> N) {
        MX = 0;
        FTree = vvi(N);
        Depth= vi(N, 0);
        int root = N-1;
        for (int i=0; i<N-1; i++) {
            int a,b; cin >> a >> b;
            FTree[a].push_back(b);
            root ^= i ^ b;      // 找出root 的方法 init root = N-1
        }
        solve(root);
        cout << MX << '\n';
    }
    return 0;
}