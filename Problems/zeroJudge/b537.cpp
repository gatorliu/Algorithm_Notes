// https://zerojudge.tw/ShowProblem?problemid=537
// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>

typedef long long ll;
#define key first
#define value second

using namespace std;

unsigned long long findK(int a, int b ) {
  if (a==b) return 1;
  if (a > b ) { // K is even)
    return 2 * findK(a-b, b);
  } else { // K is odd}
    return findK(b,a) + 1;
  } 
}


int main() {
    int a, b;
    while(cin >> a >> b) {
      cout << findK(a, b) << endl;      
    }

    return 0;
}