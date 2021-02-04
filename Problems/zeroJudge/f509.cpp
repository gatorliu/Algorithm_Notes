// https://zerojudge.tw/ShowProblem?problemid=f509
/**
延平高中資研社期末考 2020-01-08
f509: A-電梯

延平新大樓終於有電梯了
每個電梯可以載Ｎ公斤的重量
每個搭電梯的人體重Ｗ公斤
請問一台電梯最多能載幾人？

輸入說明
一行兩個整數Ｎ, W

範例輸入 #1
10 3

範例輸出 #1
3

*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    //ios::sync_with_stdio(0);cin.tie(0);
    int n, w;
    cin >> n >> w;
    cout << n/w << endl;
    return 0;
}