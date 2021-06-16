// https://tioj.ck.tp.edu.tw/problems/???
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N, x; 
    cin >> N;
    vector <int> LIS={};
    // int val[N];
    // int pos[N];
    for (int i=0 ; i<N; i++) {
        cin >> x;
        // val[i] = x;
        if (LIS.empty() || x > LIS.back()) {
            LIS.push_back(x);
            // pos[i] = LIS.size();  // 1
        } else  {
            auto it = upper_bound(LIS.begin(), LIS.end(), x); 
            *it = x;
            // pos[i] = it - LIS.begin() + 1;
        }
    }
    cout << LIS.size() << '\n';

    /* OUTPUT LIS : 從 pos 最大數字往前找
    // for(auto s : pos) cout << s << " ";
    
    vector<int> ans;
    int sz = LIS.size();
    for (int i=N-1; i>=0; i--){
        if (pos[i] == sz ){
            ans.push_back(val[i]);
            sz--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "LIS: ";
    for (auto i: ans) cout << i << " ";
    cout << '\n';
    */
    return 0;
}