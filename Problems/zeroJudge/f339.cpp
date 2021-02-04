// https://zerojudge.tw/ShowProblem?problemid=f339
// 時間複雜度 :建表O(m+n)[更新要n],查詢O(n) 解法
// 可用線段數！！
#include <iostream>
#include <algorithm>
using namespace std;

int R[(int)1e5+5]={0};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, e;
    cin >> n >> m;
    while(m--){
        cin >> s >> e;
        if(e > R[s]) R[s] = e;
    }
    /*
    for (int i=0; i<=n; i++) cout << R[i] << " ";
    cout <<endl;
    */
    // 查詢輸出
    s=0;
    int next = -1;
    for (int i=0; i<n; i++) {
        // cout << "debug: i=" << i << " R[i]=" << R[i] << " s=" << s << " next=" << next << endl;
        if (R[i] > i) {
            next = max(R[i], next);
            
            if (s > 0) {
                cout << i-s << " " << i << endl;
                s=0;
            }
        } else if (next > i) continue;
        else    s++;
        
    }
    // 處理最後一筆
    if (s>0) cout << n-s << " " << n << endl; 
}