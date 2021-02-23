// https://zerojudge.tw/ShowProblem?problemid=f161
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>
using namespace std;


typedef long long ll;
#define color first
#define cnt second

int N;
ll CLR[200000+5];
vector<int> RD[200000+5];
map<ll, int> CLRCnt;
int mx=1;

void dfs(int city){
    for (auto c : RD[city]) {
        // 取寶石
        auto it = CLRCnt.find(CLR[c]);
        if (it == CLRCnt.end()) CLRCnt.insert({CLR[c], 1});  // 沒有就新增
        else {
            (*it).cnt += 1;                                 // 有就 +1
            // 計算最大值
            if ((*it).cnt > mx) {
                //cout << city << ", " << c << endl;
                mx=(*it).cnt;
            }
        }
        dfs(c); // GO next city
        // 還寶石
        it = CLRCnt.find(CLR[c]); // 因為有可能之前是沒有
        (*it).cnt -= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    int s,t;
    for(int i=0; i<N; i++) cin >> CLR[i];
    for(int i=0; i<N-1; i++) {
        cin >> s >> t;
        RD[s].push_back(t); 
    }

    CLRCnt.insert({CLR[0], 1}); // 取寶石 city=0
    dfs(0);
    
    cout << mx << endl;
    return 0;
}