// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <queue>
#include <set>


typedef long long ll;
#define key first
#define value second


using namespace std;
map <ll, ll> V;


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    stringstream ss;
    ll k,v;
    ll ans= 0;
    getline(cin, s);
    for (int i=0; s[i] != '\0'; i++) { if (s[i] == ':' ) s[i] = ' '; }
    ss << s;
    while(true) {
      ss >> k;  ss >> v;
      if(k==0 && v == 0) break;
      V.insert({k,v});
    }

    ss.str(""); ss.clear();
    getline(cin, s);
    for (int i=0; s[i] != '\0'; i++) { if (s[i] == ':' ) s[i] = ' '; }
    ss << s;
    while(true) {
      ss >> k;  ss >> v;
      if(k==0 && v == 0) break;
      
      auto it = V.find(k);
      if (it != V.end()) {
        //cout << k << " " << (*it).value << " " << v << endl;
        ans += (*it).value * v;
      }
    }
    
    cout << ans << endl;

    return 0;
}