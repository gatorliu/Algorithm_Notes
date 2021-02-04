// https://zerojudge.tw/ShowProblem?problemid=631
// #include <bits/stdc++.h>

/*
    1. PQ.若empty, PQ.top()仍會有值喔!
    2. 一定要食物價格要全輸入後，再開始執行。
        因為有可能中間就"Oh My God"，然後後面輸入會亂掉
EX:
3 3
100 200 300
600 100 100
3 3
100 200 300
100 100 100
*/

#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>


typedef long long ll;
#define key first
#define value second


using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);

    int N,M;
    ll n, m, rich;
    while(cin >> N >> M) {
        priority_queue<int> PQ;
        vector<int> FOOD(M);
        while(N--) {
            cin >> n; 
            if (n>0) PQ.push(n);
        }
        rich = PQ.top();
        for(int i=0; i<M; i++) cin >> m, FOOD[i]= m;

        for(int i=0; i<M && rich != -1; i++){
            m = FOOD[i];
            while(m>0) {
                if (PQ.empty()) {rich = -1; break;}
                n = PQ.top(); PQ.pop();
                // cout << "\t size = "  << PQ.size() <<  " top() " << PQ.top() << endl; 
                if (n > m) { // 錢夠
                    PQ.push(n-m);
                    // cout << "    1: " << n-m << endl;
                    break;
                } else { // 錢不夠或剛好，換下一個
                    m -= n;
                     // cout << "    2: " << m << endl;
                }
            }
        }
        if (rich == -1) cout << "Oh My God" << endl;
        else cout << rich << " " <<  (PQ.empty() ? 0 : PQ.top()) << endl;        
    }   
    return 0;
}