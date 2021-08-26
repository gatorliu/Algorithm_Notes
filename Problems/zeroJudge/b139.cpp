// https://zerojudge.tw/ShowProblem?problemid=b139
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

#define f first
#define s second

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int L, M; cin >> L >> M;
    vector< pair< int, int> > V;
    V.push_back({L,-1});    //插入尾
    for (int i =0 ; i < M; i++) {
        int s,e; cin >> s >> e;
        V.push_back({s,-1});
        V.push_back({e+1,1}); // 注意:這裡要加1
    }
    sort(V.begin(),V.end(), [](pair< int, int>a, pair< int, int>b){ 
        if ( a.f == b.f) return a.s < b.s;
        else return a.f < b.f;
    });
    
    int sum = L+1;
    int flag = 1; 
    int pre = 0; // 設定開頭位置
    for (auto p: V) {
        if (flag < 1) 
            sum -= (p.f-pre);
        flag += p.s;
        pre = p.f;
        // cout << p.f << ", " << p.s  << " => ";
        // cout << sum << endl;
    }
    cout << sum << endl;
    return 0;
}