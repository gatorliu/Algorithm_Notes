// https://zerojudge.tw/ShowProblem?problemid=f632
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

/* 
考慮 有很多小費給很多，很晚來的客人
若只用 vector針對 小費給排序，將會TLE
*/

typedef long long ll;
#define t first
#define m second

using namespace std;
int T1, T2, K, P;


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T1 >> T2 >> K >> P;
    int t, m;
    vector < pair<int,int> > V;
    while (cin >> t >> m) V.push_back({t, m});
    sort(V.begin(), V.end());
    

    ll guest=0, sum=0;
    priority_queue<int> PQ;
    auto it=V.begin();
    for (int t=T1; t<=T2; t+=K) {
        for( ; (*it).t <= t && it != V.end(); it++) PQ.push((*it).m);

        for(int i=0; i<P && !PQ.empty(); i++ ) {
                guest++;
                sum += PQ.top();
                PQ.pop();
        }
            
    }
     
    cout << guest << " " << sum << endl;

    return 0;
}