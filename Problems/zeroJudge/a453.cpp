// https://zerojudge.tw/ShowProblem?problemid=a453
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;



int M, a,b,c;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> M;
    while(M--){
        cin >> a >> b >> c;
        int ans = b*b - 4*a*c;
        if (ans == 0) cout << "Yes" << endl;
        else if (ans <0) cout << "No" << endl;
        else {
            int s = sqrt(ans);
            if ( s*s == ans) cout << "Yes" << endl;
            else  cout << "No" << endl;
        }
    }

    return 0;
}