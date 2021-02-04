// https://zerojudge.tw/ShowProblem?problemid=c123
// The Tower of Hanoi
#include <iostream>
#include <stack>
using namespace std;

int step = 0;
string rail(int arr[]  , int n ){
    stack<int> station;
    for (int i=1; i<=n; i++) {
        int curr_car = arr[i];
        if (i <= curr_car) station.push(i);
        if (i >= curr_car) {
            int car = station.top();
            station.pop();
            
            if (car !=  curr_car) return "No";
        } 
    }
    return "yes";   
}

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) break;
        while(1) {
            int arr[n+1];

            cin >> arr[1];
            if (arr[0] == 0) {
                cout << endl;
                break;
            } 
            cout <<n;
            for (int i=2; i<=n; i++) cin >> arr[i];
            
            cout << rail(arr, n) << endl;
        }

    }
}