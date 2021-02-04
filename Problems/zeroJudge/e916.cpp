// https://zerojudge.tw/ShowProblem?problemid=e915
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//typedef long long ll;
typedef int ll;


#define len first 
#define no second

int solve(ll n, ll k) { 
    if (k==1) return 1;
    if (k==2) return n;
    vector< pair<ll, ll> > lst; 
    lst.push_back({(n-2), 1}); // 存負值，才可以sort
    ll ans;
    for (ll i=3; i<=k; i++) {
        auto it = lst.begin();
//    cout << "   " << (*it).no << ":" << -(*it).len << endl;
        ll len = (*it).len;
        ll no = (*it).no;
        // (*it).len = - ((l + 1) / 2 - 1);
        ans = no + ((len+1)/2);
        lst.erase(it);
//    cout << "           " << ans << ":" << -(len/2) << endl;
//    cout << "           " << no << ":" << - ((len + 1) / 2 - 1) << endl;
        lst.push_back({ (len/2) , ans });
        lst.push_back({ ((len + 1) / 2 - 1) , no });

        sort(lst.begin(), lst.end(), 
            [](pair<ll, ll>a, pair<ll, ll>b){
                if (a.len == b.len) return a.no < b.no;
                else return a.len > b.len;
            });

    } 
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll n, k ;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
        
    return 0;
}

