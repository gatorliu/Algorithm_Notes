// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;


typedef long long ll;
#define key first
#define value second

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int N; cin >> N;
    while(N--) {
        int C; cin >> C;
        int v; cin >> v;
        int ans = v;
        int tmp = v;
        
        while(--C) {
            if (tmp<0) tmp=0;
            cin >> v;
            tmp += v;
            if (tmp > ans) ans = tmp;
        }
        cout << ans << '\n';
        
    }

    return 0;
}