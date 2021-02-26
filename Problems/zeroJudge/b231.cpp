// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>

#include <vector>

using namespace std;

typedef long long ll;
#define f first
#define s second

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while (cin >> n ) {
        vector< pair<int,int> > V(n, {0,0});
        for (auto &v : V) cin >> v.f >> v.s;

        sort(V.begin(), V.end(), [](pair<int,int> a, pair<int, int> b){
            if (a.s == b.s) return a.f < b.f;
            else return a.s > b.s;
        });

        ll tm_p=0; // 印刷
        ll mx = 0; // 裝訂
        for (auto v : V) {
            if (mx == 0) {
                tm_p = v.f;
                mx = tm_p + v.s;
            }
            else {
                tm_p += v.f;
                mx = max(mx,tm_p + v.s );
            }
        }
        cout << mx << endl;
    }

    return 0;
}