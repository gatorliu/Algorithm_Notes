// https://zerojudge.tw/ShowProblem?problemid=a190
// The Tower of Hanoi   奇數號的環移到b柱上，偶數號的環移到c柱上
#include <iostream>
using namespace std;

int step = 0;
char curr_pos[1024];
char target_pos[1024];

void print_step(int ring, char to ) {
    step++;
    //cout << "ring " << ring << " : " << curr_pos[ring] << " -> " << to << endl; // 把最大一個從 Start 搬到 End
    curr_pos[ring] = to;
}

void move(int ring, char to ){
    for (int i = ring; i > 1; i--) {
        int x =  294 - curr_pos[ring] - to; // 249 = ASCII 'a'+'b'+'c'
        move(i-1, x);
        print_step(i-1, x);
        
    }
}

void move_init(int ring){    // 從最大的圈開始比對，是否位置正確。若不正確，就開始搬(move)
    step = 0;
    for (int i = ring; i >= 1; i--) {
        if (curr_pos[i] != target_pos[i]) {
            move(i, target_pos[i]);
            print_step(i, target_pos[i] );
        }
    }
    return;
}


int main() {
    int n;

    while(cin >> n) {

        // 設定 ring position
        for(int i=1; i<=n; i++) {
            curr_pos[i] = 'a';                          // all rings in 'a'
            target_pos[i] = (i&1) == 1 ? 'b' : 'c';     // 單數在'b', 雙數在'c'
        }
        move_init(n);
        cout << "total move "<< step << " steps.\n";

        /* Debug 印出位置
        for(int i=1; i<=n; i++) cout << curr_pos[i] << " ";
        cout << endl;

        for(int i=1; i<=n; i++) cout << target_pos[i] << " ";
        cout << endl;
        */
    }

    
        
}