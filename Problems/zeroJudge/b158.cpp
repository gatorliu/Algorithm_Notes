// https://zerojudge.tw/ShowProblem?problemid=b158
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;


typedef long long ll;
#define f first
#define s second


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n; 
    while(cin >>n) {
        vector< vector<int> > V(n, vector<int>(5));

        for (int i=0; i< n; i++) {
            V[i][0]= i+1;
            cin >> V[i][1] >>  V[i][2] >>  V[i][3];
            V[i][4] = V[i][1] +  V[i][2] +  V[i][3];
        }
        sort(V.begin(), V.end(), [](vector<int>a , vector<int> b){
            if ( a[4] == b[4]) {
                if ( a[1] == b[1]) return a[0] < b[0]; 
                else return a[1] > b[1];
            }  
            else return a[4] > b[4];
        });

        for (int i=0; i<5; i++) cout << V[i][0] << ' ' << V[i][4] << '\n';
    }
    return 0;
}