// https://tioj.ck.tp.edu.tw/problems/????
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;


/*
| x_n   |   | 0 1 | ^n       | x_0 |
| x_n+1 | = | a b |        * | x_1 | 


| x_n-1 |   | 0 1 | ^(n-2)   | x_1 |
| x_n   | = | a b |        * | x_2 | 

*/
ll mod = 1e9+7;
struct mat{
    ll arr[4]={0};
};

mat mat_prod(mat M, mat N) {
    mat A;
    A.arr[0] = (M.arr[0] * N.arr[0] + M.arr[1] * N.arr[2] ) % mod;
    A.arr[1] = (M.arr[0] * N.arr[1] + M.arr[1] * N.arr[3] ) % mod;
    A.arr[2] = (M.arr[2] * N.arr[0] + M.arr[3] * N.arr[2] ) % mod;
    A.arr[3] = (M.arr[2] * N.arr[1] + M.arr[3] * N.arr[3] ) % mod;
    return A;
}

map < ll, mat > dp;

mat mat_pow(mat M, mat A, int pow) {    
    while(pow) {
        if (pow & 1) {
            A = mat_prod (M, A);
        }
        M = mat_prod (M, M);
        pow >>= 1;
    }
    return A;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int x1, x2, a, b, n;
    //int A[4] = {0};
    cin >> x1 >> x2 >> a >> b >> n; 
    
    mat Q = {{ 0, 1, a, b}};
    mat X = {{x1, 0, x2, 0}};
    Q = mat_pow(Q, X, n-2);
    cout << Q.arr[2] << endl;

    return 0;
}