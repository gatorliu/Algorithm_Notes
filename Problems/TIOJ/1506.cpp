// https://tioj.ck.tp.edu.tw/problems/1506
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

double a1, a2, b1, b2;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    double x, y;
    if (a1 == a2) {
        x = b2 - b1;
    } else {
        x = ( b2-b1) / (a1-a2) ;
    }
    if (x == -0.0) x=0.0;       // 注意這裡 處理 -0.0
    y= a1 *x + b1;

    //http://www.cplusplus.com/reference/ios/ios_base/precision/
    cout.setf( ios::fixed);
    cout.precision(2);
    cout << x << "\n" << y << "\n";

    return 0;
}