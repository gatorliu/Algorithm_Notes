// https://zerojudge.tw/ShowProblem?problemid=f160
#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int T, sn, s;
    cin >> T >> sn;
    
    // 假設都切，再開始和並，合併後若大於等於t，表示不能合併
    int sum= 0, cnt =0, ps=0;
    while(sn--) {
        cin >> s;
        sum += (s -ps);
        if (sum > T) {// 需要切
            cnt++;
            sum = s -ps;
            //cout << "cut:" << ps << "  sum="<<  sum << endl;
        }
        ps = s;
    }
    if (sum > 0) cnt++; // 結束之判斷
    
    cout << cnt << endl;

    return 0;
}