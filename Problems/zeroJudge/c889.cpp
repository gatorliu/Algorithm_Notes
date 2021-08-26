// https://zerojudge.tw/ShowProblem?problemid=c889

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector< vector<int> > vii;    // init:   V = vii(3, vi(5,0));
typedef pair<int, int> pii;
 
#define PB push_back
#define F first 
#define S second 
 
int n, m; 
vii G;
vi colored;


bool solve(int v, int cnt, int color ) {
    colored[v] = color;
    for (auto v2 : G[v]) {
        int next_color = (color%2==1 ? color+1 : color-1);
        if (colored[v2] == next_color) continue;
        else if (colored[v2]== 0) {
            bool ret = solve(v2, cnt+1,  next_color);
            if (!ret) return ret;
        }
        else return false;
        
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    G = vii(n, vi());
    colored = vi(n, 0);
    
    // input  & build Graphy
    while(m--) {
       int v1, v2; cin >> v1 >> v2;
       v1--; v2--;
       G[v1].PB(v2);
       G[v2].PB(v1);
    }
    int next_color = 1;
    bool ret;
    for(int i=0; i<n ; i++) {
        if (colored[i]>0) continue;
        ret = solve(i, 1, next_color);
        if (!ret) break;    
        next_color += 2;
    }

    //cout << "colored:\n" ; for (auto v : colored) cout << v << ' ' ; cout <<endl;
    
    if (ret) {
        vi colorCnt(next_color-1,0);
        for (auto c : colored) colorCnt[c-1]++;
        int ans = 0;
        for (int i=0; i < colorCnt.size(); i+=2)
            ans += min(colorCnt[i], colorCnt[i+1]);

        cout << ans << endl;
    } else cout << "0\n";

    return 0;
 
}