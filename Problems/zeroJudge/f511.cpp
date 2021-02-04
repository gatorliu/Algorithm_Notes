// https://zerojudge.tw/ShowProblem?problemid=f511
//#include <bits/stdc++.h>

/**
延平高中資研社期末考 2020-01-08
f511: C-傳說對決

你現在在玩傳說對決，總共要出6件裝備(同件裝備可重複出)
每件裝備有三個屬性
    1. ad(物理攻擊) (0=<ad<=10^6)
    2. ap(魔法攻擊) (0=<ap<=10^6)
    3. p(爆擊率) (p=0 or 0.05 or 0.1 or 0.15 or 0.2 or 0.25 or 0.3 or 0.35 or 0.4 or 0.45 or 0.5，p只有這十種可能)

出裝備的規則如下
    1. 6件裝備的ad值, ap值, p值相加後分別為總ad值 , 總ap值 , 總p值
    2.總p值不能超過1，若超過1則以1計算(畢竟是機率)
    3.爆擊造成2倍傷害(可忽略)

而英雄傷害的期望值可用(0.2*總ad值+0.75*總ap值)*(1+總p值)表示

現在共有k件裝備，請輸出所有出裝備方式中第x高的傷害期望值

輸入說明
    第一行有一個正整數x
    第二行有一個正整數k(k<=10)
    接下來k行有三個浮點數，分別代表其中一種裝備的ad值, ap值, p值

輸出說明
    所有出裝備方式中第x高的傷害期望值，四捨五入到小數點下第2位

範例輸入 #1
1
2
70 50 0.2
100 100 0

範例輸出 #1
712.80

範例輸入 #2
2
3
250 15 0.1
550 33 0
80 0 0.15

範例輸出 #2
808.50

----------------------------------------------------------------
提示:
Use `lomg long` and `double`, not use int and float 否則會有錯!
----------------------------------------------------------------
*/
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

double P[10][3];
int x, k;
//int dp[10][6];
double V[1000000]={0};
int idx = 0;
void pick(int level, int pk, double ad, double ap, double p ) {
    if (level==6) {
        //cout << ad <<", " << ap << ", " << p << endl;
        V[idx++] = (ad*0.2 + ap*0.75) * (1+ min((double)1.0, p));
        return;
    }
    
    pick(level+1, pk, ad+P[pk][0], ap+P[pk][1], p+P[pk][2]);  // select 
    if (pk < k-1) 
        pick(level, pk+1, ad, ap, p); // not select 
}



int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    // input
    cin >> x >> k;
    for (int i=0; i<k; i++ ) {
        cin >> P[i][0]  >> P[i][1]  >> P[i][2];
    }
    pick(0, 0, 0.0, 0.0, 0.0);

    sort(V, V+idx, [](double x, double y) {return x>y;});
    ll ans =  (ll) (V[x-1]*1000);
    ans =  (ans %  10 < 5) ? ans -( ans % 10) : ans -( ans % 10) + 10;

    cout << ans/1000 << ".";
    ans = ans % 1000;
    cout <<  (ans/100) << (ans % 100 / 10)<< endl;
    return 0;
}