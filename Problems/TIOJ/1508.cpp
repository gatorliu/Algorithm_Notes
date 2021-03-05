// https://tioj.ck.tp.edu.tw/problems/???
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

// 問題轉化成背包: 所有數字取或不取，值為 總數一半
// 不加DP  O(2^n)
//更好的DP https://yuihuang.com/tioj-1508/

int N, M;
int D[105] ={0};
bool dp[105][50005] = {0};

bool solve(int idx, int sum) {
    if (sum == 0 ) return true;
    else if (sum < 0 || idx <= 0 || dp[idx][sum] == 1) return false;

    bool a = solve(idx-1, sum-D[idx]);
    if (a) return true;
    else dp[idx][sum-D[idx]] = 1;
    

    if (idx ==1) return false;
    a = solve(idx-1, sum);
    if (a) return true;
    else dp[idx-1][sum-D[idx]] = 1;
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >>M >> N;
    while(M--) {
        int preSum=0;
        for(int i=0; i<N; i++) for(int j=0; j<50005; j++) {dp[i][j] = 0;}
        for(int i=0; i<N; i++) {
            cin >> D[i];
            preSum +=D[i];
        }
        if (preSum & 1) cout << "No" << endl;
        else {
            preSum /= 2;
            if (solve(N-1, preSum) ) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}