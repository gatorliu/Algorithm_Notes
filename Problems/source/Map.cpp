//#include <bits/stdc++.h>
#include<iostream>
#include<queue>
#include <iomanip>
using namespace std;

const int N  = 1000 + 5;
int gamemap[N][N][4] = {};

struct state {
    int x;
    int y;
    int life;
};

int moves[4][2] ={{-1, 0},{1, 0},{0, 1},{0, -1}}; //　上下左右


int x, y, a, b, B, T ;
state ssta, esta; // start_state, end_state
queue<state> que;

void bfs() {
    que.push(ssta); 
    while(que.size() > 0) {
        state me = que.front(); que.pop();
        //cout << me.x << ", " << me.y << ", me.life = " <<  me.life  << ", step  = " << gamemap[me.x][me.y][me.life] << endl;
        int step = gamemap[me.x][me.y][me.life] + 1;
        int row, col, l;
        for (int i=0; i<4; i++) {    //push 4 directs step to queue
            row = moves[i][0] + me.x;
            col = moves[i][1] + me.y;
            l = me.life;
            if ( row < 0 || row >= x || col < 0 || col >= y ) continue;  // outside of boundary
            if (esta.x == row && esta.y == col) { // 到達
                gamemap[row][col][0] = step; // 儲存步數在　gamemap[esta.x][esta.y][0]
                return;
            }
            if (gamemap[row][col][0] == -1)   continue;                // next step is barrier
            if (gamemap[row][col][0] == -2) --l;                       // next is trape => life -1
            // cout << "   " << row << ", " << col << ", l = " <<  l << endl;
            if ( l > 0 && gamemap[row][col][l] == 0 ) { // not die and not reach next state(postion & lift) yet 
                gamemap[row][col][l] = step;
                que.push({row, col, l});
            }
            
        }
    }
} 

int main() {
    cin >> x >> y;
    cin >> a >> b ; ssta = {a, b, 3};
    cin >> a >> b ; esta = {a, b, 3};
    cin >> B >> T;   // Barrier, Trape
    for (int i=0; i < B; i++)  {
        cin >> a >> b ; gamemap[a][b][0]= -1;
    }
    for (int i=0; i < T; i++)  {
        cin >> a >> b ; gamemap[a][b][0]= -2;
    }
    // input dome.

    //* output map
    for (int i=0; i < x; i++)  {
        for (int j=0; j < y; j++)   {
            if (ssta.x == i && ssta.y == j) cout << setw(3) << 'S';
            else if (esta.x == i && esta.y == j) cout << setw(3) << 'E';
            else cout << setw(3) <<gamemap[i][j][0];
        }
        cout << endl;
    }
    //*/

    bfs();
    cout << gamemap[esta.x][esta.y][0] << endl;
}

/* sample
input:
4 6
0 5
0 0
3 2
0 4
1 2
2 3
1 3
1 4

map:
  E  0  0  0 -1  S
  0  0 -1 -2 -2  0
  0  0  0 -1  0  0
  0  0  0  0  0 -1 

output:
7

input:
4 6
0 5
0 0
4 3
0 4
1 0
1 2
2 3
0 1
1 3
1 4

map:
  E -2  0  0 -1  S
 -1  0 -1 -2 -2  0
  0  0  0 -1  0  0
  0  0  0  0  0 -1 

output:
11


input:
6 5
0 4
0 2
8 6
1 1
3 1
4 1
0 3
1 3
2 3
3 3
4 3
0 1
1 0
2 0
3 2
4 2
5 2
map:
  0 -2  E -1  S
 -2 -1  0 -1  0
 -2  0  0 -1  0
  0 -1 -2 -1  0
  0 -1 -2 -1  0
  0  0 -2  0  0

output:
16

*/