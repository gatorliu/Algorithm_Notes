// https://zerojudge.tw/ShowProblem?problemid=ce022

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
//#include <utility>
//#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector< vector< pair<int, int> > > vvp;
typedef vector< int > vi;

#define F first 
#define S second 
 

vvp G;
vector< bool > PSE; // PSE == Path Start or End (只有一座可動式橋的城市)
vi used;


int solve(int c, int l, int Limit) { // L = path length
    //cout << c << endl;
    if (l> Limit) return -1;
    used[c] = 1;
    int ret = -1;
    if ( l%2 == 0) { // A區
        for(auto nc : G[c]) {
            if (used[nc.F]) continue;
            if (nc.S == 0)  //下一個必須是可動式橋
                ret = max( ret, solve(nc.F, l+1, Limit) );
        }   
    } else { // B區 (可能是結尾)
        if (PSE[c]==1 ) { //可以當結尾 
            ret = l;
        }
        for( auto nc : G[c]) {
            if (used[nc.F]) continue;
            if (nc.S == 1)  //下一個必須是水泥橋
                ret = max( ret, solve(nc.F, l+1, Limit) );
        }
    }
    used[c] = 0;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int m, n, k, Limit; 
    while (cin >> m >> n >> k >> Limit) { 
        G = vvp(m+n+10);
        PSE= vector< bool > (m+n, true);
        used= vi(m+n, 0);
        
        while (k--) {
            int a,b, t;
            cin >> a >> b >> t;
            a--; b+=(m-1);
            G[a].push_back({b, t});
            G[b].push_back({a, t});
            if (t==1) {
                PSE[a] = 0;
                PSE[b] = 0;
            }
        }
        // cout << endl; for(auto g: G) { for(auto v: g) cout << "(" << v.F << ", " << v.S << ")  ";  cout << endl; }
        // cout << endl; for(int i=0; i <m+n; i++) cout << PSE[i] << " ";  cout << endl; 
        
        //由於路徑必是單數，所以只要從A區找即可
        int max_path = -1;
        for(int i=0; i<m; i++) {
            if (!PSE[i]) continue;
            max_path = max(max_path, solve(i, 0, Limit));
        }
        cout << max_path << '\n';
    }    
    return 0;
 
}