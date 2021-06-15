// https://zerojudge.tw/ShowProblem?problemid=e446
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
void printout(int n){
    int i;
    for (i = 0; i < n-1; i++) 
        cout << arr[i] << " ";
    cout << arr[i] << "\n";
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin >> n) {
        for (int i=0; i< n; i++) arr[i]=i+1;
        std::sort (arr,arr+n);
        do {
            printout(n);
        } while ( std::next_permutation(arr, arr+n) );
    }
}