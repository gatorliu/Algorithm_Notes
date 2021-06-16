// https://zerojudge.tw/ShowProblem?problemid=b230
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <set>
using namespace std;


typedef long long ll;
#define f first
#define s second

int p (int a, int b, int c) {return a*b+b*c+c*a; }
int main() {
    set<ll> S;
    int A=60, B=61, C=62;
    for (int i=1; i<=p(A,B,C); i++) S.insert(i);
    for (int a=1;a<=A;a++) {
        for (int b=a+1;b<=B;b++) {
            for (int c=b+1;c<=C;c++) {
                S.erase(p(a,b,c));
            }
        }
    }
    //cout << S.size();
    /*
    for (auto s: S) {
        cout << s << " ";
    }
    */
    int k;

    while(cin >> k)
        cout << *next(S.begin(), k -1) << endl;
    

    return 0;
}