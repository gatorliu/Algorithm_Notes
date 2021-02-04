// https://zerojudge.tw/ShowProblem?problemid=e446
#include <iostream>
using namespace std;

int arr[10];
void printout(int n){
    int i;
    for (i = 0; i < n-1; i++) 
        cout << arr[i] << " ";
    cout << arr[i] << endl;
}

bool find (int num, int cur) {
    for (int i=0; i< cur; i++) {
        if (num == arr[i])  return true;
    }
    return false;
}

void p(int n, int cur) {
    if (n == cur){
        printout(n);
    }
    else 
    {
        for (int i=1; i<=n; i++) {
            if (find(i, cur) != true) {
                arr[cur]= i;
                p(n, cur+1);
            }
            
        }
    }
}


int main() {
    int n;
    while(cin >> n) {
        p(n, 0);
    }
}