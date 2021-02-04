// https://zerojudge.tw/ShowProblem?problemid=f633
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/**
       16 17
       18 19
 12 13  0  1  4  5  8  9
 14 15  2  3  6  7 10 11
       20 21
       22 23
*/
int CMD[5][12] = {
        {    0,0,0,0, 0,0,0,0,     0,0,0,0},
        {    4,5,7,6, 1,17,10,21, 3,19,8,23},
        {16,17,19,18, 0,12,8,4,   1,13,9,5},
        {12,13,15,14, 0,20,11,16, 2,22,9,18},
        {20,21,23,22, 2,6,10,14,  3,7,11,15}
    };

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    int dict[24] = {1,1,1,1,2,2,2,2,6,6,6,6,5,5,5,5,3,3,3,3,4,4,4,4};
    while(cin >> n) {
        int t;
        for (int s = 11; s >= 0 ; s--) {
            if (s == 11 || s==7 || s==3) t = dict[CMD[n][s]];
            else if (s==8 || s == 4 || s==0 ) {
                dict[CMD[n][s]] = t;
                continue;
            }
            dict[CMD[n][s]] = dict[CMD[n][s-1]];
        }
    }
    cout << dict[0]  << " " << dict[1] << "\n" << dict[2] << " " << dict[3] << endl;

    return 0;
}