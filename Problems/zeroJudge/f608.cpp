// https://zerojudge.tw/ShowProblem?problemid=f608

#include <iostream>
#include <vector>
//#include <utility>
#include <algorithm>
using namespace std;

#define x first 
#define y second
//typedef long long ll;

int n;

// O(N^2) 遞迴加上DP
vector<int> dp(200000+5,0);
int solve(int idx,  vector< pair<int, int> > foods)  {
    int x, y, mx = 1; 
    if (idx == -1 ) {
        x = y = 0;
    } else {
        if (dp[idx] != 0) return dp[idx];    
        x =  foods[idx].x;
        y = foods[idx].y;
        mx = 1;
    }
    for(int i=idx+1; i<foods.size(); i++) {
        if( x <= foods[i].x  && y <= foods[i].y ) {
            mx = max(mx, solve(i, foods)+1);
        }
    }
    dp[idx] = mx;
    return mx;
}

/* 把二維的y軸，看成一個1維的數列，問題就轉化成了 LIS */
/* LIS 最佳解法 O(N *logN) :  DP + Binary Search */
vector<int> DP;
int LIS(vector< pair<int, int> > foods) {
    for (auto f : foods) {
        int idx = upper_bound(DP.begin(), DP.end(), f.y ) - DP.begin();
        //cout << idx << endl;
        if (idx == DP.size() ) {
            DP.push_back(f.y);            
        } else {
            DP[idx] = f.y;
        }
    }
    return DP.size() ;
}
/*
bool cmp(pair<int, int>a, pair<int, int>b) {
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector< pair<int, int> > foods(n);

    for(auto &f: foods) {
        cin >>f.x >> f.y;
    }
    sort(foods.begin(), foods.end()
        , [](pair<int, int>a, pair<int, int>b) { // lambda cmp
            if (a.x == b.x) return a.y < b.y;
            else return a.x < b.x;}
    );
    /* Debug sort
    int xx =-1;
    for(auto f: foods) {
        if (xx != f.x ) {xx = f.x; cout << endl; cout << xx << " : ";}
        cout << " " << f.y;
    }
    cout << endl;
    */
    // cout << solve(-1, foods) -1 << endl; // 因為起始位置(idx=-1)沒有food, 所以-1
    cout << LIS(foods) << endl;
    return 0;
}

