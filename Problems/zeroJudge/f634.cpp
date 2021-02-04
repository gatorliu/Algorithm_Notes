// https://zerojudge.tw/ShowProblem?problemid=f634
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
#define A first
#define B second

using namespace std;


bool duplicate(map < string, set <pair <int,int> > > &MP, string S, int A, int B) {
    auto it = MP.find(S);
    if ( it == MP.end()) {
        //cout << "\t No get S:"  << S << " " << MP[S].size() << endl;
        MP.insert({S, {}});
        MP[S].insert({A,B});
        return false;
    } else {
        auto &st = it->second;
        if (st.find({A,B}) != st.end()) {
            //cout << "\t get S, A, B: size"  << (*st).size() << endl;
            return true;
        } else {
            //cout << "\t no get S, A, B: size"  << (*st).size() << endl;
            st.insert({A,B});
            return false;
        }
    }
          
}

int cntA[4]={0}, cntB[4]={0};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    map <string, set < pair <int,int> > > MP;
    int n, m, A, B;
    string S;
    cin >> n >> m;
    while(m--) {
        cin >> S >> A >> B;
        if (duplicate(MP, S, A, B)) continue;

        cntA[A]++;
        cntB[B]++;
        
    }
    cout << "navy:"<< cntA[1] << " army:" << cntA[2] << " air:" << cntA[3] << endl;
    cout << "officer:"<< cntB[1] << " sergeant:" << cntB[2] << " soldier:" << cntB[3] << endl;
    ll rate = (ll)round(((double)(cntA[1]+cntA[2]+cntA[3]) / n * 1000));
    cout << "survival rate: " << rate / 10 << "." << rate % 10 << "%\n";

    return 0;
}