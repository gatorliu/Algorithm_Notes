// https://zerojudge.tw/ShowProblem?problemid=b232
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int  M , N, IDX;
int HouseSet[380];
ll dp[755][380];

ll solve(int house, int idx) {
    if (house == 0) return 1;
    if (idx < 0 ) return 0;
    if (dp[house][idx] != 0) return dp[house][idx];
    
    ll cnt=0;
    if (house >= HouseSet[idx]) {
        cnt = solve(house - HouseSet[idx], idx);  // pick
    } 
    cnt += solve(house, idx-1); // not pick
    dp[house][idx] = cnt;

    return cnt;
}


int main() {
    // init coins
    for(int i=0, c=1;i< 380; i++, c+=2 ) HouseSet[i]= c;
    
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> M;
    while (M) {
        cin >> N;
        IDX = N/2;
        //init DP
        for(int i=0; i<=N; i++) for(int j=0; j<=IDX; j++) dp[i][j] = 0;
        cout << solve(N, IDX) << "\n";
        M--;
    }
    
    return 0;
}