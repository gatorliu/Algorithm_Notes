// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
using namespace std;

int divid[3], rem[3];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    for (int i=0; i<3; i++)
        cin >> divid[i] >> rem[i];
    
    int st[3]={0,1,2};

    sort(st, st+3, [](int a,int b){return divid[a] < divid[b];});
    
    int ans = rem[st[0]];
    
    int p = divid[st[0]];   
    while (ans % divid[st[1]] != rem[st[1]] ) ans += p;

    p = p*divid[st[1]]; 
    while (ans % divid[st[2]] != rem[st[2]]) ans += p;

    cout << ans << endl;

    return 0;
}