// https://zerojudge.tw/ShowProblem?problemid=e915
/*
    96%答對，但其實應該不能int
    但只有一題 TLE ??

    改成 long long 有多題應該是，超出記憶體錯誤
*/

#include <iostream>
#include <set>

#include <algorithm>
using namespace std;
typedef long long ll;
//typedef int ll;



#define len first 
#define no second

int solve(ll n, ll k) { 
    if (k==1) return 1;
    if (k==2) return n;
    set< pair<ll, ll> > lst;
    lst.insert({(n-2), 1}); // 存負值，才可以sort
    ll ans;
    for (ll i=3; i<=k; i++) {
        auto it = lst.begin();
//    cout << "   " << (*it).no << ":" << -(*it).len << endl;
        ll len = -(*it).len;
        ll no = (*it).no;
        // (*it).len = - ((l + 1) / 2 - 1);
        ans = no + ((len+1)/2);
        lst.erase(it);
//    cout << "           " << ans << ":" << -(len/2) << endl;
//    cout << "           " << no << ":" << - ((len + 1) / 2 - 1) << endl;
        lst.insert({ -(len/2) , ans });
        lst.insert({ -((len + 1) / 2 - 1) , no });

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
        set< pair<ll, ll> > lst; 
        cout << solve(n, k) << endl;
    }
        
    return 0;
}