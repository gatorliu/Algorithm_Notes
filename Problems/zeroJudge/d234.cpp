// https://zerojudge.tw/ShowProblem?problemid=d234
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// 只要 c ~ c + a 都可以，就可以
vector<int> DP={0};
bool solveC (int a, int b, int c) {
    if (c < 0) return 0;
    if (c == 0) return 1;
    if (DP[c] !=-1 ) return DP[c];

    bool ret;
    // pick b
    ret = solveC(a, b, c-b);
    if (ret) { DP[c] = 1; return 1; }
    
    // pick a
    ret = solveC(a, b, c-a);
    if (ret) { DP[c] = 1; return 1; }

    DP[c] = 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b ,c;

    while(cin >> a >> b >> c) {
        if (a>b) swap(a, b);
        DP.clear(); DP.resize(c+a, -1);
        bool flag = 1;
        //if (c > a*b) c = a*b;
        for (int cc=c; cc < c+a; cc++) {
            if (!solveC(a, b, cc)) {
                cout << "No\n";
                flag = 0;
                break;
            }           
        }
        if (flag) cout << "Yes\n";
    }
return 0;
}