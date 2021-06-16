// https://tioj.ck.tp.edu.tw/problems/2190
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
ll M, a, b, X1, Y1, X2, Y2;

ll powM(ll a, ll b) {
    a %=M; // 注意這行一定要，否則會爆!!
    if (b == 0) return 1;
    else if (b & 1) {
        return(a * powM(a, b-1)) % M;
    }
    else {
        return powM(a*a, b>>1) % M;
    }
} 
/*
ll powM(ll a, ll b) { 
    ll ans =1;
    while (b) {
        if (b & 1) ans = ans * a % M;

        a = a * a % M; 
        b >>= 1;
    }
    return ans;
}
*/

ll getm(ll X1, ll Y1, ll X2, ll Y2) { 
        ll ret = ((((Y2- Y1) % M) + M) % M) * powM((X2-X1), M-2)  % M;
        ret %= M;
        //if (ret < 0) ret +=M;
        return ret;
}

ll getY3( ll m, ll x ) {  
    ll k = Y1- m * X1;
    k = ( (k % M) + M) % M;
    ll ret = x*m + k;
    ret = ( (ret % M) + M ) % M;
    return ret;
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int t;    cin >> t;
    while (t--) {
        cin >>  M >>  a >>  b >>  X1 >>  Y1 >>  X2 >> Y2;
        ll m = getm(X1, Y1, X2, Y2);
        //cout << "m = " << m << " : ";
        ll x3 = (((m*m - X1 - X2 ) % M ) + M) % M;
        while (x3 <0 ) x3+=M;
        //x3 %= M;
        cout <<  x3 <<  " " << getY3(m, x3) << endl;
    }
    return 0;
}