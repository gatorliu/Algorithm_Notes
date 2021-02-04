#include <iostream>
#include <utility>
using namespace std;

int x, y, n;

/* 
    state:
    0 : 下(上沒有，左右下有一格)
    1 : 左 (右邊沒有)
    2 : 上 (下沒有) 
    3 : 右 (左沒有)
*/
int move(pair<int,int> &c, int state, int step) {
    if (step <0 || step > 4 ) return state;
    if ( (state == 2 && c.second == y - 1) || (c.second == y - 2 ) ) return state;
    c.second +=1;
    if(step == 1) { // 右移
        if (state == 1) {
            if (c.first <= x - 2 ) c.first +=1;
        } else {
            if (c.first <= x - 3 ) c.first +=1;
        }
    } else if(step == 2) { // 左移
        if (state == 3) {
            if (c.first >= 1 ) c.first -=1;
        } else {
            if (c.first >= 2 ) c.first -=1;
        }
    } else if(step == 3) { //下
        if (state == 2) {
            c.second = y - 1;
        } else {
            c.second = y - 2;
        }
    } else if(step == 4) {
        switch (state) {
            case 0:
                state = 1;
                break;
            case 1:
                if( c.first < x-1) state = 2;
                break;
            case 2:
                if( c.second < y-1) state = 3;
                break;
            case 3:
                if( c.first > 0) state = 0;
                break;

        }
        
    }
    return state;
}

int main() {
    int n, step;
    pair<int,int> c;   
    cin >> x >> y >> n;
    c = make_pair((x-1)/2, 0);
    int state = 0; 

    //cout << "----" << c.first << " " << c.second << " " << state << endl;
    while (n--) {
        cin >> step;
        state  = move(c, state, step);
        //cout << step << "----" << c.first << " " << c.second << " " << state << endl;        
    }
    
    //out put
    int grid[105][105] = {0};
    grid[c.second][c.first] = 1;
    
    if (state !=2) grid[c.second+1][c.first] = 1;
    if (state !=0) grid[c.second-1][c.first] = 1;
    if (state !=1) grid[c.second][c.first+1] = 1;
    if (state !=3) grid[c.second][c.first-1] = 1;
    
    for (int i = 0; i< y; i++) {
        for (int j = 0; j< x; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}