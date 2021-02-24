// https://zerojudge.tw/ShowProblem?problemid=b229
// #include <bits/stdc++.h>

/* 
F(n) = 2*F(n-1) + F(n-2)

證明:
F(1) = 3 
F(2) = 7 = 上 + 左右 =  上 + 2*右 = F(1) + 2*2
F(3) = 17 = 上 + 左右 =  F(2) + 2 * [ F(1) + 2]
                        上   + 2 * _____右_________
F(4) = F(3) + 2 * [F(2) + F(1) + 2]
       _上_ + 2 * _____右_________
     = F(3) + F(2) + F(2) + 2 *[ F(1) + 2]
     = F(3) + F(2) + F(3)
     = 2 * F(3) + F(2)
*/
#include <iostream>

using namespace std;
typedef unsigned long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll arr[51];
    int N;
    
    arr[0] = 0;
    arr[1] = 3;
    arr[2] = 7;
    for(int i=3; i<=50; i++) {
        arr[i] = 2*arr[i-1] + arr[i-2];
    }
    while(cin >> N) {
        cout << arr[N] << endl;
    }
    return 0;
}