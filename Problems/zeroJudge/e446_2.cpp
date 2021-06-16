// https://zerojudge.tw/ShowProblem?problemid=e446

// 用 next_permutation沒有比較快!

#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
char buffer[10000000];
long long  bidx = 0;
void printout(int n){
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] < 10)  {
            buffer[bidx++]=arr[i] + '0';
        }
        else {
            buffer[bidx++]='1';
            buffer[bidx++]='0';
        }
        buffer[bidx++] = ' ';
    }
    buffer[bidx++] ='\n';
    if (bidx > 10000000-50) {
        buffer[bidx] ='\0';
        cout << buffer ;
        bidx = 0;
    }

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

        if (bidx > 0) {
            buffer[bidx] ='\0';
            cout << buffer ;
            bidx = 0;
        }
    }
}