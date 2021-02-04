// https://zerojudge.tw/ShowProblem?problemid=b002
/* 未解
#include <iostream>
using namespace std;

const int N = 10;
int arr[N][N];
int change[4][2] ={{-1, 0},{1, 0},{0, -1},{0,1}};

int turn(int r, int c) {
    if (arr[r][c]
    for (int i=0; i < 4; i++) {
        
    }
}

int main() {
    int times;
    cin >> times;
    while(times--) {
        int cnt=0;
        int x;
        for (int r=0; r<N; r++){
            for(int c=0; c<N; c++) {
                cin >> x;
                if (x == 'O') {
                    cnt++;
                    arr[r][c] = 1;
                } else arr[r][c]=0;
            }
        }

    }
}
