// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
int dice[21];
int dicePoint[21][3];
int N, M, a, b;

/**
 * dicePoint[i][0]  正面
 * dicePoint[i][1]  右面
 * dicePoint[i][2]  左面
**/

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        dice[i]=i;
        dicePoint[i][0]=1;
        dicePoint[i][1]=2;
        dicePoint[i][2]=3;
    }

    while(M--) {
        cin >> a >> b;
        switch(b) {
            case -1:  // 向前轉
                swap(dicePoint[dice[a]][2], dicePoint[dice[a]][0]);
                dicePoint[dice[a]][2] = 7 -  dicePoint[dice[a]][2];
                break;

            case -2: // right 
                swap(dicePoint[dice[a]][0], dicePoint[dice[a]][1]);
                dicePoint[dice[a]][0] = 7 -  dicePoint[dice[a]][0];
                break;
            
            default:
                swap(dice[a], dice[b]);
        }

    }
    // out put
    for (int i=1; i<=N; i++) {
        cout << dicePoint[dice[i]][0] ;
        if (i == N) cout << "\n";
        else cout << " ";
    }


    return 0;
}