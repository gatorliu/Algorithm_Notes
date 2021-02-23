// https://zerojudge.tw/ShowProblem?problemid=f647
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <list>
using namespace std;

string A[53]={
    "XX",
    "SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
    "HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
    "DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
    "FA","F2","F3","F4","F5","F6","F7","F8","F9","F10","FJ","FQ","FK"
};
int Cards[53]; 
int N, cmd, a, b;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=52 ; i++) { Cards[i] = i;}

    cin >> N;
    int tmp[53];
    int link;
    int diff;
    while(N--) {
        cin >> cmd;
        switch(cmd) {
            case 1:
                cin >> a >> b;
                diff= b-a+1;
                for(int i = a; i<=b; i++) tmp[i] = Cards[i];
                for(int i=a-1; i>=1 ; i--) Cards[i+diff] = Cards[i];
                for(int i = 1; i<=diff; i++) Cards[i] = tmp[a+i-1];
                break;
            case 2:
                cin >> a >> b;
                diff= b-a+1;
                for(int i = a; i<=b; i++) tmp[i] = Cards[i];
                for(int i=b+1; i<=52 ; i++) Cards[i-diff] = Cards[i];
                for(int i=a; i<=b; i++) Cards[52-b+i] = tmp[i];
                break;
            case 3:
                cin >> a;
                b=52; a = 52- a + 1; 
                //same case 1
                diff= b-a+1;
                for(int i = a; i<=b; i++) tmp[i] = Cards[i];
                for(int i=a-1; i>=1 ; i--) Cards[i+diff] = Cards[i];
                for(int i = 1; i<=diff; i++) Cards[i] = tmp[a+i-1];
                break;
            case 4:
                cin >> b;
                a = 1; 
                //same case 2
                diff= b-a+1;
                for(int i = a; i<=b; i++) tmp[i] = Cards[i];
                for(int i=b+1; i<=52 ; i++) Cards[i-diff] = Cards[i];
                for(int i=a; i<=b; i++) Cards[52-b+i] = tmp[i];
                break;
        }
    }

    for (int i = 1 ; i <=5; i++) { 
        cout << A[Cards[i]] <<  " ";
    }
    cout << "\n";
    return 0;
}