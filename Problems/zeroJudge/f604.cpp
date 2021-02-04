// https://zerojudge.tw/ShowProblem?problemid=604
/**
延平高中資研社期末考 2020-01-08
f604: D-Water Heater

我們有一個熱水器，每分鐘可提供W公升的熱水(水量無法累積!!)
現在有N個人，每個人要在Si~Ti(含Ti但不含Si)的時間裡，每分鐘使用Pi的熱水量
請問熱水是否夠用?

輸入說明
    第一行2個整數 N, W (1≤N≤2×10^5, 1≤ W ≤10^9)
    接下來N行
    S1 T1 P1  (0≤ Si<Ti≤2×10^5, 1≤ Pi ≤10^9)
    ....
    Sn Tn Pn
輸出說明
    Yes or No


範例輸入 #1
4 10
1 3 5
2 4 4
3 10 6
2 4 1

範例輸出 #1
No

範例輸入 #2
4 10
1 3 5
2 4 4
3 10 6
2 3 1

範例輸出 #2
Yes

範例輸入 #3
6 1000000000
0 200000 999999999
2 20 1
20 200 1
200 2000 1
2000 20000 1
20000 200000 1

範例輸出 #2
Yes
*/

// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
//#include <vector>
//#include <queue>
#include <set>

typedef long long ll;
#define t first
#define w second

using namespace std;

int N, s, t; // 2*1 e5
ll W, p; // 1e9;

set<int> IDXs;
int Ws[200000+5] ={0};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >>N >> W;

    // input
    while (N--) {
        cin >> s >> t >> p;
        Ws[s] += p; IDXs.insert(s);
        Ws[t] -= p; IDXs.insert(t);
    }

    ll sum=0;
    for (int idx : IDXs) {
        //cout << Ws[idx] << endl; 
        sum += Ws[idx];
        if (sum > W )  {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}