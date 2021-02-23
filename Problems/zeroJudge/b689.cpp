// https://zerojudge.tw/ShowProblem?problemid=b689
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <queue>
using namespace std;

struct dt {
    int r;
    int c;
};

queue<dt> que;

char MP[25][25];
//int used[21][21] = {0};
int ans[2];


int way[4][2] = {{-1,0}, {1, 0}, {0,-1}, {0, 1}};
void bfs() {
    int r, c;
    while(!que.empty()) {
        dt d = que.front(); que.pop();
        ans[0]= d.r; ans[1]= d.c;
        //cout << d.r << " " << d.c << endl;

        for (int i=0; i<4; i++) {
            r = d.r + way[i][0];
            c = d.c + way[i][1];
            //cout << '\t' << r << " " << c << endl;

            if(MP[r][c] == '#') continue;
            else {
                MP[r][c]='#';
                que.push({r, c});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int R, C;
    int r, c;
    string  s;
    for(int i=0; i< 25; i++) for(int j=0; j< 25; j++) MP[i][j] = '#';
    // input
    cin >> R >> C;
    for(int i=1; i<= R; i++) {
        cin >> s;
        for (int j=1; j<=C; j++) {
            MP[i][j] = s[j-1];
            if ( (i == 1 || j ==1 || i==R || j==C ) && s[j-1] == '.') {
                r=i; c=j;
                MP[i][j] = '#';
            }
        }
    }
    /*
    for(int i=0; i< 21; i++) {
        for(int j=0; j< 21; j++) cout << MP[i][j];
        cout << endl;
    }
    */
    que.push( {r,c} );
    bfs();
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
/*----------------------------------------------------------------

7 9
#########
##.....##
##.###.##
##.#...##
##.#.##..
#..#....#
#########
ANS:
6 2


7 9
######.##
##.....##
##.####.#
##.#....#
##.#.##.#
#..#....#
#########
ANS:
6 2
*/