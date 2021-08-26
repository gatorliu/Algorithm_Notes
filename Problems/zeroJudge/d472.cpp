// https://zerojudge.tw/ShowProblem?problemid=d472
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define MX 110000
#define MD 76543


vector<ll> P;
void PrimeTable() {
    vector<int> num(MX,0);
    // for faster
    for (int x = 1; 2*x < MX; x++)  num[2*x] = 1; 
    P.push_back(2); 
    // ----------

    for (int i=3; i <MX; i+=2) {
        if (num[i] == 1) continue;
        else {
            P.push_back(i); 
            if (P.size()==10000) break;
            for (int x = 1; i*x < MX; x++)  num[i*x] = 1;
        }
    }
}

ll modpow(ll n, int k) {
    ll ans = 1;
    while( k ) {
        if (k&1) ans = (ans*n) % MD;
        n = (n * n ) % MD;
        k >>= 1;
    }
    return ans % MD;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    PrimeTable();
    //for (int i=9991; i< 10005; i++) cout << P[i] << " "; cout << endl;
    ll ans=1;
    int cnt=0;
    int k;

    while( cin >> k) {
        ans *= modpow(P[cnt++], k);
        ans %= MD;
    }
    cout << ans << endl;
    return 0;
}