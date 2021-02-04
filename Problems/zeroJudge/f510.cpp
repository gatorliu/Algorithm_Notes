// https://zerojudge.tw/ShowProblem?problemid=f510
/**
延平高中資研社期末考 2020-01-08
f510: B-大樓

延平有兩座大樓，昭陽樓和進英樓，簡稱A大樓和B大樓(好爛的簡稱==
 A,B兩大樓都有100層樓高(這是在異世界的延平，不要太在意細節^-^)
以 Ai , Bi 代表 A , B 大樓的第 i 層樓(1=<i<=100)
    1. Ai 和 Bi 之間有雙向通道連接(1=<i<=100)
    2. Ai+1 和 Bi 之間有雙向通道連接(1=<i<=99)
    3. Ai 和 Ai+1 之間、Bi 和 Bi+1 之間有雙向樓梯連接(1=<i<=99)

走一次通道需花費 x 分鐘，走一次樓梯需花費 y 分鐘
求從 Aa 走到 Bb 的最小時間(分鐘)

輸入說明
    一行四個整數a,b,x,y(1=<a,b,x,y<=100)
輸出說明
    從 Aa 走到 Bb 的最小時間(分鐘)

範例輸入 #1
2 1 1 5

範例輸出 #1
1

範例輸入 #2
1 2 100 1

範例輸出 #2
101

範例輸入 #3
1 100 1 100

範例輸出 #2
199

*/
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    //ios::sync_with_stdio(0);cin.tie(0);
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;
    
    if (a == b ) cout << x << endl;
    else {
        ll z = 2*x;
        if (z > y) swap(z,y);
    
        if ( a < b)     
            cout << x + (b-a)* z << endl;
        else // a > b
            cout << x + (a-b-1)* z << endl;
    }
    return 0;
}