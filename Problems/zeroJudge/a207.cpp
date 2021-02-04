// https://zerojudge.tw/ShowProblem?problemid=a207

#include <iostream>
using namespace std;
int Mat[10005][10005] = {0};

int N, M;
int main() {
    ios::sync_with_stdio (false);
    cin.tie(0);
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int t; cin >> t;
        for(int j=0; j< t; t++) {
            int k; cin >> k;
            Mat[i] |= 1<< k;
        }
    }    

}