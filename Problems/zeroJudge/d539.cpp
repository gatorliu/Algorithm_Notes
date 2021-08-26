// https://zerojudge.tw/ShowProblem?problemid=d539
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> segTree;
vector<int> arr;
/*
segTree[1] = max(arr[0,....n]) =  max(segTree[1], segTree[2]);
segTree[2] = max(arr[0,....n/2]);
segTree[3] = max(arr[n/2+1,....n]);
*/

void build ( int l, int r, int idx) {
    if (l == r) {
        segTree[idx] = arr[l];
        return;
    }
    int m = (l + r)/2;
    int li = idx*2;   // left index
    int ri = li+1; // right index
    build(l, m, li);
    build(m+1, r, ri );

    segTree[idx] = max(segTree[li], segTree[ri]);
}

int queryTree ( int L, int R, int l, int r, int idx) {
    if (l==r) return segTree[idx];
    if (L==l && R==r) return segTree[idx];

    int m = (l + r)/2;
    int li = idx*2;   // left index
    int ri = li+1;    // right index

    if ( R <= m) return queryTree (L, R, l, m, li ); // Left
    else if ( L > m) return queryTree (L, R, m+1, r, ri ); // Right
    else {  // Separate and Merge
        return max(  // Merge
            queryTree (L, m, l, m, li ),  // Separate to  Left,
            queryTree (m+1, R, m+1, r, ri ) // Separate Right
        );
    }

        
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    segTree = vector<int> (4*n+5);
    arr = vector<int> (n);
    for(auto &v: arr) cin >> v;

    build(0, n-1, 1);
    // for(auto v: arr) cout << v << ' '; cout << endl;
    // for(auto v: segTree) cout << v << ' '; cout << endl;
    
    int t; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;
        if (l >r ) swap(l,r);
        cout << queryTree( l-1, r-1, 0, n-1, 1) <<  '\n';
    }
    
    
    return 0;
}