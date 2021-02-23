// https://zerojudge.tw/ShowProblem?problemid=g174
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <list>
using namespace std;

typedef long long ll;


int N, K;
vector<ll> V;
list<int> MQ; // 單調隊列 (Monotone Queue)


// 單調隊列處理
ll getMaxSum(int cv, int k) {
    V[k] = V[k-1] + cv;

    // push to MQ 入隊
    while (!MQ.empty() && V[MQ.back()] > V[k]) MQ.pop_back(); 
    MQ.push_back(k);

    // pop form MQ 出隊
    while(k- MQ.front() > K ) MQ.pop_front();

    return V[k] - V[MQ.front()];
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    
    // init
    V.resize(N+1);  V[0]=0;
    MQ.push_back(0);

    int cv; //cake value
    ll q_max=0, mx=0;
    for(int i=1;i<=N; i++) {
        cin >> cv;
        q_max = getMaxSum(cv, i);
        //cout << "q_max = " << q_max << endl;
        if (mx < q_max) mx = q_max;
    }
    cout << mx << endl;
    return 0;
}