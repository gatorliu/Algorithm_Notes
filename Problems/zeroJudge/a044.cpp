// https://zerojudge.tw/ShowProblem?problemid=a044
#include <iostream>
using namespace std;
/* 
公式 :
    A(n)  = A(n-1) + [ n-1 條線可以分割多少平面]
          = A(n-1) + C(n,2) + 1       when n >= 2
          = A(n-1) + (n*n - n)/2 + 1  

          = (n^3+ 5n +6) / 6 
*/
int A(int n) {
    if (n ==1) return 2;
    //else if (n == 2) return 4;
    else {
        return A(n-1) + (n*n - n)/2 + 1 ;
    }
}

int main() {
    int n;
    while(cin >> n)
        cout << A(n) << endl;
}
