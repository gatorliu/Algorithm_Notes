// https://zerojudge.tw/ShowProblem?problemid=e915
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define angry first     // angry
#define t second // time


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector< pair<int, int> > cust(n);

    for(auto &c: cust) {
        cin >>c.angry>> c.t;
    }

    sort(cust.begin(), cust.end(), 
        [](pair<int, int>a, pair<int, int>b ) {return a.angry*b.t > b.angry* a.t;}
    );

    ll ans=0, tm = 0;
    for(auto c: cust) {
        //cout << c.angry << " "; 
        tm += c.t;
        ans += c.angry * tm;
    }
    cout << ans << endl;
    return 0;
}

