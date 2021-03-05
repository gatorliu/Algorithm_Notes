// https://tioj.ck.tp.edu.tw/problems/???
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

// TLE 作法
int N, M;
int D[105] ={0};

bool solve(int idx, int sum, int preSum) {
    if ( preSum < sum || -preSum  > -sum) return false;
    if (idx == 0) {
        if (sum + D[0] == 0 || sum - D[0] == 0 ) return true;
        else return false;
    }
    if (solve(idx-1, sum + D[idx], preSum-D[idx])) return true;
    else return solve(idx-1, sum - D[idx], preSum-D[idx]);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >>M >> N;
    while(M--) {
        int preSum=0;
        for(int i=0; i<N; i++) {
            cin >> D[i];
            preSum +=D[i];
        }
        sort(D,D+N);
        if (preSum & 1) cout << "No" << endl;
        else if (solve(N-1, 0, preSum) ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}