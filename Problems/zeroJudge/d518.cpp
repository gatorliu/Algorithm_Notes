// https://zerojudge.tw/ShowProblem?problemid=d518
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

const int MAXn = 2e5+5;
int nxt[MAXn][26], num[MAXn][26], nodeCnt;

bool findAndInsert(string s, int no ) { // if insert return 0 else return 1(find)
        int chr, nxtIdx=0;
        for(int i=0; s[i]!='\0'; i++) {
                chr = s[i] - 'a';
                if (nxt[nxtIdx][chr] == 0 ) { // new node
                        nxt[nxtIdx][chr] =  ++nodeCnt;
                }
                nxtIdx = nxt[nxtIdx][chr];
        }
        if (num[nxtIdx][chr] == 0 ) {
                num[nxtIdx][chr] = no;
                cout << "New! " << no << '\n';
                return 0;
        } else {
                cout << "Old! " << num[nxtIdx][chr] << '\n';
                return 1;
        }
}
/*
void debug_print() {
    for(int i=0; i<10 ; i++) {
        for(int j=0;j<26;j++) {
                cout << nxt[i][j] << ' '; 
        }
        cout << endl;
    }
}
*/
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
        int n;
        string s;
        while(cin >> n) {
                //init
                nodeCnt=0;
                memset(nxt, 0, sizeof(nxt));
                memset(num, 0, sizeof(num));

                int oldcnt = 0;
                for(int i=1; i<=n ; i++) {
                    cin >> s;
                    oldcnt += findAndInsert(s, i-oldcnt);
                    //debug_print();
                }
        }
    return 0;
}