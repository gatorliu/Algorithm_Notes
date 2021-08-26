// https://zerojudge.tw/ShowProblem?problemid=b326
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> G(n, -1);
        vector<int> V(n, 0);
        int u, v;
        for(int i=1; i<n; ++i) {
            cin >> u >> v;
            G[v]= u;
        }
        int q; cin >> q;
        char o;
        while (q--) {
            cin >> o >> v;            
            if ( o == 'M') V[v] ^= 1;
            else {
                int ret  = -1;
                while(v != -1) {
                    if (V[v] == 1) {
                        ret = v;
                        break;
                    } else
                        v = G[v];
                }
                cout << ret << '\n';
            }
        }
    }

    return 0;
}