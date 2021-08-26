// https://zerojudge.tw/ShowProblem?problemid=d575
//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    long long ox, oy, vx, vy, d;
    while(cin >> ox >> oy >> vx >> vy >> d) {
            if ( abs(ox - vx) + abs(oy-vy) - d  > 0 ) cout << "alive\n";
            else cout << "die\n";        
    }
    return 0;
}