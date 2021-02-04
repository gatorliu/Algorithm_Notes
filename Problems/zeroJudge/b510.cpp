// https://zerojudge.tw/ShowProblem?problemid=b510
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

#define col first
#define t second

pair<int, char> G[10];
int cnt = 0;
int SZ;

bool check_queen(int r, int c) {
    for (int rr = 0 ; rr<r; rr++) {
        if (G[rr].col== c) return false;
        else {
            int dist = abs(r-rr);
            if ( 
                ( G[rr].col + dist < SZ &&  G[rr].col + dist  == c ) 
                || 
                ( G[rr].col - dist > -1 &&  G[rr].col - dist  == c ) 
            ) return false;
        }
    }
    return true;
}
bool check_castle(int r, int c) {
    for (int rr = 0 ; rr<r; rr++) {
        if (G[rr].col== c) return false;
        else if(G[rr].t == 'q') {
            int dist = abs(r-rr);
            if ( 
                ( G[rr].col + dist < SZ &&  G[rr].col + dist  == c ) 
                || 
                ( G[rr].col - dist > -1 &&  G[rr].col - dist  == c ) 
            ) return false;
        }
    }
    return true;
}

void dfs(int m, int n) { 
    if (m+n == 0) {
        cnt++;
        return;
    }
    int row = SZ- m -n;
    for( int c=0; c< SZ; c++) {
        if (m>0 && check_queen(row,c)) {
            G[row].col = c;
            G[row].t = 'q';
            dfs(m-1, n);
            G[row].col = -1;
            G[row].t = '-';
        } 
        //cout << row << ", " << c << " : " << endl;
        //cout << check_castle(row,c) << endl;
        if (n>0 && check_castle(row,c)) {
            
            G[row].col = c;
            G[row].t = 'c';
            dfs(m, n-1);
            G[row].col = -1;
            G[row].t = '-';
        }  
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int M,N;
    cin >> M >> N;
    SZ = M+N;
    for(int i=0; i<SZ;i++) G[i]= {-1, '-'};

    dfs(M, N);
    cout << cnt << endl;

    //for(int i=0; i<SZ;i++) cout << G[i].t << endl ;

    return 0;
}