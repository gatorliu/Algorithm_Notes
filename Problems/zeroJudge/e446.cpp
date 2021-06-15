// https://zerojudge.tw/ShowProblem?problemid=e446
#include <iostream>
using namespace std;

int arr[10];
bool flag[12] = {0};
void printout(int n){
    int i;
    for (i = 0; i < n-1; i++) 
        cout << arr[i] << " ";
    cout << arr[i] << "\n";
}

void p(int n, int cur) {
    if (n == cur){
        printout(n);
    }
    else 
    {
        for (int i=1; i<=n; i++) {
            if (flag[i]) 
                continue;
            else 
            {
                arr[cur]= i;
                flag[i]= 1;
                p(n, cur+1);
                flag[i]= 0;
            }
            
        }
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin >> n) {
        p(n, 0);
    }
}