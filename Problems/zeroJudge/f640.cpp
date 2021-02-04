// https://zerojudge.tw/ShowProblem?problemid=f640
// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>

typedef long long ll;
#define key first
#define value second


using namespace std;
/*
ll f (ll x) { return 2*x -3;}
ll g (ll x, ll y) { return  2*x + y - 7 ;}
ll h (ll x, ll y, ll z) { return 3*x - 2*y+ z;}
*/


vector<string> Q;


ll solve(int &idx) {
    int v=0;
    //cout << "idx= " << idx << endl; // ", fun = " << fun  << ", arg=" << arg << endl;
    if (idx==Q.size()) return 0;

    if (Q[idx][0]-'0' >=0 && Q[idx][0]-'0' <=9 || Q[idx][0] == '-' ) {
            v = stoi(Q[idx]);
            return v;
    }
    if ( Q[idx] == "f") {
        return 2*solve(++idx) - 3;
    }
    else if ( Q[idx] == "g") {
         ll x = solve(++idx);
         return 2*x + solve( ++idx ) - 7;
    }
    else if ( Q[idx] == "h") {
         ll x = solve(++idx); 
         ll y = solve(++idx);
         return 3*x - 2*y  + solve(++idx);
    }
    return 0;
}


int main() {
    //ios::sync_with_stdio(0);cin.tie(0);
    string s;
    getline(cin, s);
    stringstream ss; ss << s;
    ll v;

    while(ss >> s) {
        Q.push_back(s);
    }
    //cout << "index =" << index << endl;
    int idx =0;
    cout << solve(idx) << endl;


    return 0;
}