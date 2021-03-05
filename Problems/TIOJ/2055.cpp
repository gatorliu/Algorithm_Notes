// https://tioj.ck.tp.edu.tw/problems/2055
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
#define f first
#define s second

int N;
vector<int> B; 
vector<int> ST; 

void build(int L, int R, int idx) {
    if (L == R) { 
        ST[idx] = B[L];
        return;
    }
    int M = (L+R)/2;
    int lidx = idx *2; 
    int ridx = lidx +1;
    build(L, M, lidx);
    build(M+1, R, ridx );
    ST[idx] = min(ST[lidx], ST[ridx]);
}

int query(int l, int r, int L, int R, int idx ) {
    if (l==L && r == R) { 
        return ST[idx];
    }
    int M = (L+R)/2;
    int lidx = idx *2; 
    int ridx = lidx +1;

    if (r<=M) { // left part
        return query(l, r, L, M, lidx);
    } else if (l >= M+1) { // right
        return query(l, r,  M+1, R, ridx );
    } else { // crose over
        return min (
            query(l, M, L, M, lidx), 
            query(M+1, r,  M+1, R, ridx )
        );
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    B.resize(N);
    for(int i=0; i<N; i++) cin >> B[i];
    ST.resize(4*N);
    build(0, N-1, 1);
    //for(auto v : ST) cout << v << " ";

    int l, r;
    for(int i=0; i<N; i++) {
        cin >> l >> r ;   // l, r 要-1 因為 L是從0開始
        cout << query(l-1, r-1, 0, N-1, 1) + 1<< '\n';
    }
    return 0;
}