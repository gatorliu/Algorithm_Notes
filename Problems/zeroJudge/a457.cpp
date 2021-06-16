// https://zerojudge.tw/ShowProblem?problemid=a457
// #include <bits/stdc++.h>

/*
根據地一行排序，然後問題就相當於:
第二行的資料，由小到大排序，要移動多少次。
bubble sort  O(N^2)
mrege sort  O(NLogN)
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
#define f first
#define s second
int K;
ll M;
vector < pair<ll, ll> > Ks;
ll ans=0;

void merge_sort(int l, int r) {
    //cout << l <<  " " << r << endl;
    if (l == r ) return;

    int mid = (l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);

    vector < pair<ll, ll> > tmp;
    int il = l, ir = mid+1;

    while( il <= mid || ir <= r) {
        if (il > mid)       tmp.push_back(Ks[ir++]);
        else if (ir > r)    tmp.push_back(Ks[il++]);
        else if (Ks[il].s <= Ks[ir].s) { 
            //cout << Ks[il].s <<  " <=" << Ks[ir].s << endl;
            tmp.push_back(Ks[il]);
            il++;
        } else {
            tmp.push_back(Ks[ir]);
            ans += (mid - il + 1); // 右移到左，要計算距離位置(移了多少位置)
            ir++;
        }
    }
    for(int i=l; i<=r; i++) Ks[i] = tmp[i-l];
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> K >> M;
    Ks = vector< pair<ll, ll> >(K, {0,0});
    for (auto &k :Ks) cin >> k.f;
    for (auto &k :Ks) cin >> k.s;

    sort(Ks.begin(), Ks.end(), [](pair<ll, ll> a, pair<ll, ll> b){
                                    if (a.f == b.f) return a.s < b.s;
                                    else return a.f < b.f;
                                });
    // for(auto k: Ks) cout << k.f << " "; cout << endl;
    // for(auto k: Ks) cout << k.s << " "; cout << endl;
    
    merge_sort(0, K-1);
    cout << ans << endl;
    return 0;
}