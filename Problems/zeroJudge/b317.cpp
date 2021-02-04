// https://zerojudge.tw/ShowProblem?problemid=b317
// #include <bits/stdc++.h>
#include <iostream>

#include <utility>
#include <cmath>


typedef unsigned long long ull;
using namespace std;

int t;
ull N, R, C;
int main() {
    cin >> t;
    while(t--) {
        cin >> N >> R >> C;
        int r = R%4, c=C%4;
        if ( (r <=1 && c <= 1) || (r >=2 && c >= 2) ) { //在對角線上
            R=(N-R)+1;  C=(N-C)+1;
        }
        cout << (R-1)*N + C << endl;
    }

    return 0;
}