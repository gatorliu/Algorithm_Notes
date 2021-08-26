// https://zerojudge.tw/ShowProblem?problemid=a010
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 100005; // sqrt(100000000) == 10000
int Num[MAX]={0};
vector<int> Prime;

void buildPrimeTable(int n) {
    n = (int) sqrt(n) +2;
    int i=2; 
    do {
        Prime.push_back(i);
        for (int j=i+i; j < MAX ;j+=i) Num[j] = 1;
        while(Num[++i] == 1 && i < MAX );
    } while (i < MAX ) ;
    //for (int p : Prime) cout << p << ' ';
}
void solve(int n) {
    int cnt;
    bool flag=false;
    for (int p : Prime) {
        if ( p > n ) break;
        cnt = 0;
        while (n % p == 0) {
            cnt += 1;
            n /= p;
        }
        // print out 
        if (cnt > 0) {
            if (flag) cout << " * ";
            
            if (cnt == 1) cout << p;
            else cout << p  << "^" << cnt;
            flag = true;
        }
    }
    if (n != 1) {
        if (flag) cout << " * ";
        cout << n;
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    buildPrimeTable(n);

    solve(n);
}
