// https://zerojudge.tw/ShowProblem?problemid=d718
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;


typedef long long ll;
#define key first
#define value second

int main() {
    //ios::sync_with_stdio(0);cin.tie(0);
    int n;
    int cnt = 1;
    while(cin >> n) {
        vector<int> G(1000000, 0);
        int a, b; 
        queue<int> group_que;
        vector< queue<int> > used_group(n+1);


        for (int i=1; i<=n; i++) {
            cin >> a;
            for (int j=0; j<a; j++) {
                cin >> b;
                G[b] = i;
            } 
        }
        cout << "Line #" << cnt++ << "\n";
        string cmd;
        while(cin >> cmd) {
            if (cmd == "STOP") break;
            else if (cmd == "DEQUEUE" ) {
                b =  group_que.front();
                if (b <= 0) {
                    cout << -b << '\n'; 
                    group_que.pop();
                }
                else {
                    cout << used_group[b].front() << '\n'; 
                    used_group[b].pop();

                    if (used_group[b].size() == 0) {
                        group_que.pop();
                    } 
                }               
            }
            else if (cmd == "ENQUEUE" ) {
                cin >> a;
                b = G[a]; // 團體號
                if (b == 0) //  不屬於任何團體
                {
                    group_que.push(-a); 
                } else {
                    if(  used_group[b].size() == 0 )
                        group_que.push(b);
                
                    used_group[b].push(a);
                }
            }
        }
    }

    return 0;
}