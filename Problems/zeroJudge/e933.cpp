// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    string s, w, ans= "impossible";
    int len, find=0;
    cin >> s;
    len = s.length();
    while(cin >> w) {
        if (len != w.length()) continue;
        else if (find==1) continue;

        // 是否是加密
        map<char, char> MP, MP2;
        find = 1;
        for(int i =0; i<len; i++) {
            if(s[i] == w[i]) {
                find = 0; break;
            }
            auto it = MP.find(s[i]);
            auto it2 = MP2.find(w[i]);
            if( it == MP.end() ) { // not found
                if (it2 == MP2.end()) {
                    MP.insert({s[i], w[i]});
                    MP2.insert({w[i], s[i]});
                }
                else { 
                    find = 0;  break;
                }
            } else { // found!!
                if ((*it).second != w[i]) {
                    find = 0;  break;
                }
                else if (it2 == MP2.end() ) {
                    find = 0;  break;
                }
                else if ((*it2).second != s[i]) {
                    find = 0;  break;
                }
            }
        }
        if (find) ans = w;
    }
    cout << ans << endl;
    return 0;
}