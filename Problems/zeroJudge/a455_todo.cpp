// https://zerojudge.tw/ShowProblem?problemid=a455

//  TLE 但 DP 很難加

// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int B, T;
vector<int> Box;
vector<int> Things;
map<string, int> dp;
// int dp[55][1005];

int solve(int t) {
    if (t==T) return 0;
    
    string key="";
    for (auto bx :Box) 
        key += to_string(bx) + "_";

    auto it = dp.find(key);
    if (it != dp.end()) return (*it).second;
    

    ll w = Things[t];
    int pickCnt = 0;
    for (auto &bx :Box) {
        if (bx - w >= 0 ) { // pick Things[t]
            bx-=w;
            pickCnt  = max(pickCnt, solve(t+1)+1);    
            bx+=w;
        }
        pickCnt = max(pickCnt, solve(t+1) ); // Don't pick
    }
    dp.insert({key, pickCnt});
    return pickCnt;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    //for(int i=0; i<55; i++) for(int j=0; j<1005; j++) dp[i][j]=-1;
    
    // input
    cin >> B >> T;
    Box = vector<int>(B);    for(auto &b : Box) cin >> b;
    Things = vector<int>(T); for(auto &t : Things) cin >> t;

    cout << solve(0) << endl;
    return 0;
}