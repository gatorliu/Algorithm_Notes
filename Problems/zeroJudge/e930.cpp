// https://zerojudge.tw/ShowProblem?problemid=e930
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
#define city first
#define fee second

int N, K, u, v, w;
int M;
vector< pair<int, int> >  G[100000+5]; // Graph

struct qd{ // Queue data
    // int pre_city; 可以不考慮是否走回頭路
    int step;
    int city;
    int total_fee;
};

queue<qd> Q;

int ans = 10000001;
void bfs() {
    while(!Q.empty()) {
        qd qdata = Q.front(); Q.pop();
        int next_step =  qdata.step + 1;

        for (auto node : G[qdata.city]) {
            int curr_fee = qdata.total_fee + node.fee;
            if (curr_fee >= ans) continue; // 不加這一行會 RE: bad_alloc 應該是超出 Memory Limit
            else if (node.city == N-1) { // 到達
                ans = curr_fee;
            } else if ( next_step == K) continue; // 超出K的步數
            // else if (qdata.pre_city == node.city) continue; // 走回頭路
            else {
                //try {
                    Q.push({next_step, node.city, curr_fee});
                //} catch (std::bad_alloc& ba) {
                //    //ans = Q.size();
                //}
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    while(M--) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    Q.push({0, 0, 0});
    bfs();
    if (ans >= 10000001) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}