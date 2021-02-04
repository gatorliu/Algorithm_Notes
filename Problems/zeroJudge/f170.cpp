// https://zerojudge.tw/ShowProblem?problemid=f170

#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
};
const int M= 1000+5;
int N;
int MP[M][M] = {0};
bool used[M][M] = {0};
queue<Point> que;

int mv[4][2] = {{-1, 0}, {1,0}, {0,-1},{0,1}};
int move(int x, int y) {
    int m =0;
    for(int k=0; k<4;k++) {
        int xx = x + mv[k][0];
        int yy = y + mv[k][1];
        
        if ( xx<N && xx >= 0 && yy<N && yy >= 0 
            &&  used[xx][yy]==false 
            && abs(MP[x][y] - MP[xx][yy] ) <= 2)
        {
            que.push({xx,yy});
            used[xx][yy]=true;
            m+=1;
        }
    }
    return m;
}


int main() {
    int x, y;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> x >> y;
    
    for(int i=0; i <N; i++)for(int j=0; j<N; j++) cin >> MP[i][j];

    // solve
    Point p;
    int ans = 1;
    ans += move(x,y); used[x][y]=true;
    //cout << ans << endl;
    while(!que.empty()) {
        p = que.front(); que.pop();
        ans += move(p.x, p.y);
    }
    cout <<ans << endl;
}