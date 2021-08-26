// https://zerojudge.tw/ShowProblem?problemid=a074
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 44722; // sqrt(2000000000) == 44721.35
int Num[MAX]={0};
vector<int> Prime;

void buildPrimeTable() {
    int i=2; 
    do {
        Prime.push_back(i);
        for (int j=i+i; j < MAX ;j+=i) Num[j] = 1;
        while(Num[++i] == 1 && i < MAX );
    } while (i < MAX ) ;
    //for (int p : Prime) cout << p << ' ';
}
int solve(int n) {
    long long sum = 0;
    for (int p : Prime) {
        if ( p*p > n ) break;
        while (n % p == 0) {
            sum += p;
            n /= p;
        }
    }
    return (n==1) ? sum : sum+n ;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    buildPrimeTable();
    
    while(cin >> n)
        cout << solve(n) << '\n';
}
