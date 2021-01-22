// https://zerojudge.tw/ShowProblem?problemid=f428
// https://zerojudge.tw/ShowProblem?problemid=f432
// 輸入x,y 會超出範圍 
#include <iostream>
using namespace std;

long long solve( int n, int x1, int x2, int y1, int y2) {
    x1 -= n;
    x2 -= n;
    y1 -= n;
    y2 -= n;

	if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    long long ans = (x2-x1+1) *(y2-y1+1) *n; // 計算出全部區域都是 n的面積

    // 意思是，從正中間(value = 1)，往外擴散，找出範圍
    // 每次都把該範圍全部-1
    for (int i=0; i<n-1; i++) { 
        int x3 = max(-i, x1);
        int x4 = min(i, x2);
        int y3 = max(-i, y1);
        int y4 = min(i, y2);
        if (x4 >= x3 and y4 >= y3) {
            //cout << " - " << (x4-x3+1)*(y4-y3+1) << endl;
            ans -= (x4-x3+1)*(y4-y3+1);
        }
    }
    return ans;
}


int main() {
    
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;    
    
    cout << solve(n, x1, x2, y1, y2) << endl;
}