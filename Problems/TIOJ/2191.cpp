// https://tioj.ck.tp.edu.tw/problems/???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
struct led{ int x, y, w; };

int gcd (int a, int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    if ( b == 0 ) return a;
    else return gcd (b, a%b);
}

ll mcs (vector <ll> W) { // 最大連續和環狀，利用前綴和與單調隊列
    int sz = W.size();
    vector<ll> PrefixSum(sz*2+1, 0);
    for (int i=0; i<sz; i++) PrefixSum[i+1] = PrefixSum[i] + W[i];
    for (int i=0; i<sz; i++) PrefixSum[i+sz+1] = PrefixSum[i+sz] + W[i]; 
    deque<ll> dq;
    dq.push_back(0);
    ll ans = PrefixSum[0];

    for (int j=1; j<=sz*2; ++j) {
        if (dq.front() < j-sz) // 超出sz範圍 
            dq.pop_front();
        
        ans = max(ans, PrefixSum[j] - PrefixSum[dq.front()]); 

        // 保持單調隊列
        while ( (!dq.empty()) && PrefixSum[j] <= PrefixSum[dq.back()])
            dq.pop_back();

        dq.push_back(j);  // 放 j 到 單調隊列
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int  N, x, y ,w;
    
    cin >> N;
    vector <led> L(N);
    
    for (auto &l : L) {
        cin >> x >> y >> w;
        if ( y<0 ) { x=-x; y=-y; }
        else if (y == 0 ) x = 1e5;
        else if (x == 0) y=1;
        else {
            int g = gcd (x, y);
            x /= g;  y /=g ;
        }
        l = {x,y,w};

    }
    
    sort(L.begin(), L.end(), [](led a, led b) {
                            //if (a.x == 0 && b.x == 0) return false;
                            if (a.y == 0 || b.y == 0) return a.x < b.x;
                            return (ll)a.x * b.y < (ll)b.x * a.y;
                            });
    x=-1e5-5; y=-1e5-5;
    vector <ll> W;
    for (auto l: L) {
        //cout << l.x << ", " << l.y << " : " << l.w << endl;
        if (l.x == x && l.y == y) { 
            W[W.size()-1] += l.w;
        } else {
            W.push_back(l.w);
            x = l.x; y = l.y;
        }
    }
    L.clear();
    cout << mcs(W) << endl;
    return 0;
}