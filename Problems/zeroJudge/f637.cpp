// https://zerojudge.tw/ShowProblem?problemid=637
/* 
測資一:
DF-Expression: 2200101020110
    => 2 (2 (0 0 1 0 ),  1, 0, 2 (0 1 1 0 ) )
    =>
        2 1    => 2(0 0 1 0), 1(1 1 1 1) 
        0 2    => 0(0 0 0 0), 2(0 1 1 0)
    =>
        0 0 1 1 
        1 0 1 1  
        0 0 0 1 =>  7個 1
        0 0 1 0
*/

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

string str;
int N;
ll cnt = 0;
int idx = 0;

void decomperss(int n) {
    //cout << "idx=" << idx << ", str[idx]=" << str[idx] << endl;
    for (int p = 0; p<4; p++) {
        idx++;
        switch (str[idx-1]) {
            case '0':
                break;
            case '1':
                cnt += n*n;
                break;
            case '2':
                decomperss(n/2);
                break;
        } 
      
    }

    return;
}


int main() {
    //ios::sync_with_stdio(0);cin.tie(0);
    cin >> str >> N;
    decomperss(N);
    cout <<  cnt << endl; 

    return 0;
}