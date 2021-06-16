//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define x first
#define y second
int N, L, W;
map < ll, vector <ll>  > MP;
vector<ll> yVec;

int solve() { // 找出 L 長度內包含最多的 y 
        sort(yVec.begin(), yVec.end());
        yVec.push_back(1000005);

        int mx=0, tmp=0;
        for(auto it=yVec.begin(); *it+L <= yVec.back() ; it = upper_bound(yVec.begin(), yVec.end(), *it)) {
                //cout << it - yVec.begin() << "::" << lower_bound(yVec.begin(), yVec.end(), *it+L) - yVec.begin() << endl;;
                tmp = lower_bound(yVec.begin(), yVec.end(), *it+L) - it;
                //cout << tmp << endl;
                if (tmp > mx) mx = tmp;
        }
        return mx;
}
int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> N >> L >> W;
        for(int i=0; i<N; i++) {
                ll x,yy;
                cin  >> x >> yy;
                auto it = MP.find(x);
                if (it == MP.end()) {
                        vector<ll> v;
                        v.push_back(yy);
                        MP.insert({x, v});
                } else {
                        (*it).y.push_back(yy);
                }
        }
        /* debug output
        for ( auto &c: MP) {
                cout <<  c.x << ": " ;
                for (ll yy : c.y)  cout << yy<< "," ;
                cout << endl;
        }
        cout << "---------" << endl;
        */

        // solve
        int ans = 0;
        int slv= 0;
        for (auto it=MP.begin(); it!=MP.end(); it++) {
                yVec = (*it).y;
                // cout << (*it).x << "------------\n" ;
                for (auto it2=it; it2!=MP.end() && (*it2).x <= (*it).x+W; it2++) {
                        // cout << (*it2).x << "\t=>" ;
                        if(it2 != it) {
                                for (ll y: (*it2).y) {
                                        // cout << y << " ";
                                        yVec.push_back(y);
                                }
                        }
                }
                // cout << (*it).x << "------------\n" ;
                slv = solve();
                if (slv > ans) ans = slv;
        }
        cout << ans << endl;
}