// https://tioj.ck.tp.edu.tw/problems/1080
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

// 
typedef long long ll;
#define f first
#define s second

// tmp 用   arr + index      Time: 92ms
// tmp 用vector + index      Time: 116ms
// tmp 用vector + push_back  Time: 116ms
int tmp[100005];
ll merge_sort(int l, int r,  vector<int> &V) {
    
    if(l == r) return 0;
    ll ans=0;
    int mid = (l + r)/2;
    ans = merge_sort(l, mid, V);
    ans += merge_sort(mid+1, r, V);

    // merge here.
    
    int il= l, ir= mid+1;
    //while(il <= mid || ir <= r) {
    for(int t=0; t <= r-l; t++) {
        if ( ir > r ) tmp[t] = V[il++]; //tmp.push_back(V[il++]);
        else if ( il > mid ) tmp[t] = V[ir++]; //tmp.push_back(V[ir++]);
        else if ( V[il] <= V[ir]) {
            tmp[t] = V[il++]; //tmp.push_back(V[il]);
            //il++;
        } else {
            tmp[t] = V[ir++]; //tmp.push_back(V[ir]);
            ans += (mid - il + 1); 
        }
    }
    for (int i=l; i<=r; i++) V[i] = tmp[i-l];
    return ans;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, cnt=0;
    while (cin >> n) {
        if (n==0) break;
        cnt++;
        vector<int> V(n);
        for (int &v : V) {
            cin >> v;
        }
        cout << "Case #" << cnt << ": " << merge_sort(0, n-1, V) << "\n";
    }

    return 0;
}