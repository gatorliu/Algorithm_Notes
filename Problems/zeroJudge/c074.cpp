// https://zerojudge.tw/ShowProblem?problemid=c074
#include <iostream>
using namespace std;


int data[15];
int arr[15];
int NUM_OF_PICK= 6;
void printout(int n){
    int i;
    for (i = 0; i < NUM_OF_PICK-1; i++) 
        cout << arr[i] << " ";
    cout << arr[i];
}

void p(int n, int cur, int data_cur) {
    if (NUM_OF_PICK == cur){
        printout(n);
        cout << endl;
    }
    else 
    {
        for (int i=data_cur; i < n; i++) {
            arr[cur]= data[i];
                p(n, cur+1, i+1);
            }
    }
}


int main() {
    int n;
    while(cin >> n) {
        if (n == 0) return 0;    
        for (int i=0; i< n; i++)
            cin >> data[i];

        p(n, 0, 0);
    }
}