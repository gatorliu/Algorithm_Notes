// https://zerojudge.tw/ShowProblem?problemid=a227
// The Tower of Hanoi
#include <iostream>
using namespace std;

void move(int n , char start, char end, char tmp ){
    if (n == 1) {
        cout << "Move ring " << n << " from " << start << " to " << end << endl; // 把最大一個從 Start 搬到 End
    } else {
        move(n-1, start, tmp, end );
        cout << "Move ring " << n << " from " << start << " to " << end << endl; // 把最大一個從 Start 搬到 End
        move(n-1, tmp, end, start );
    }
}


int main() {
    int n;
    while(cin >> n)
        move(n, 'A', 'C', 'B');
}