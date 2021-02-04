// https://zerojudge.tw/ShowProblem?problemid=f338
#include <iostream>
using namespace std;

int main() {
    int x0, y0, L, R;
    int N;
    int x, y, level;

    cin >> x0 >> y0 >> L >> R;
    cin >> N;
    int ans = 0;
    while(N--){
        cin >> x >> y >> level;
        if ( L < level) continue;
        if ( (x0-x)*(x0-x) + (y0-y)*(y0-y) <= R*R ) ans++; 
    }
    cout << ans << endl;
}