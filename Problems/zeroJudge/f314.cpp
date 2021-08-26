// https://zerojudge.tw/ShowProblem?problemid=f314
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef vector< int > vi;
typedef vector< vector<int> > vii;
typedef long long ll;

#define f first
#define s second

int m, n ;
vii MP;

vi solve (vi pre, vi row) {
    vi ansL(n);
    ansL[0] =  pre[0] + row[0];
    for (int i=1; i<n; i++ ) { //從左到右走 (同時考慮上方下來)
        ansL[i] = max( pre[i] + row[i], ansL[i-1]+row[i]);
    }
    vi ansR(n);
    ansR[n-1] =  pre[n-1] + row[n-1];
    for (int i=n-2; i>=0; i-- ) { //從右到左走 (同時考慮上方下來)
        ansR[i] = max( pre[i] + row[i], ansR[i+1]+row[i]);
    }

    vi ans(n);
    for (int i=0; i<n; i++ ) { // 取最大的， 即是走到該位置，最大值
        ans[i] = max(ansL[i], ansR[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n;
    MP = vii(m, vi(n));
    vi ans(n,0);
    for (auto &m: MP) {
        for (auto &n: m) {
            cin >> n;
        }
        ans =  solve(ans, m);
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;

}