// https://zerojudge.tw/ShowProblem?problemid=a160
#include <iostream>
using namespace std;
/* 
    8 皇后問題

*/
int sz;
int Queen[20] = {};
int counter;
void print(int Q[]) {
    counter++;
    for (int i=1; i <= sz; i++) {
        for (int j=1; j <= sz; j++) 
            cout << ( Q[i]==j ? 'Q' : 'x') ;
        cout << '\n';
    }
    cout << '\n';
}

bool check(int x1, int y1, int Q[]) {
    for (int x2=1; x2 < x1; x2++) {
        int y2= Q[x2];
        if ( x1 == x2 || y1 == y2 || x1+y1 == x2+y2 || x1-y1 == x2- y2 ) {
            return false;
        }
    }
    return true;
}

void queens_problem(int row, int Q[]) {
    int x1 = row;

    if (row > sz) {
        print(Q);
        return ;
    }
    for (int y1 = 1; y1 <= sz; y1++) {
        //cout << x1 << ", "  << y1 << endl;
        if (check(x1, y1, Q)) {
            Q[x1] = y1;
            queens_problem(row+1, Q);
            Q[x1] = 0;
        } else {
            continue;
        }

    }
       
}



int main() {
    while(cin >> sz) {
        if (sz == 0) break;
        counter = 0;
        
        queens_problem(1, Queen);
        cout << counter << endl;

    }
    return 0;
}