// https://zerojudge.tw/ShowProblem?problemid=???
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

typedef long long ll;
#define key first
#define value second


using namespace std;
int Coin[6];
int N;
vector <int> cnt(6,0);
vector < vector<int> > ans;

void solve(int M, int idx) {
    if (M == 0) {
        ans.push_back(cnt);
        return;
    }
    if (M >= Coin[idx]) {
            cnt[idx]++;
            solve(M- Coin[idx], idx);
            cnt[idx]--;
    }
    if (idx>0)
        solve(M, idx-1);

}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> Coin[i];
    sort(Coin, Coin+N);
    int Money;
    cin >> Money;

    solve(Money, N-1);

    sort(ans.begin(), ans.end(), [](vector <int>a, vector <int>b) {
            for (int i=0; i<N; i++) {
                if (a[i] < b[i]) return true;
                else if(a[i] > b[i]) return false;
            }
            return false;
        });

        for (auto it=ans.begin(); it != ans.end(); it++) {
            cout <<"("; 
            for (int n=0;n<N; n++) {
                cout << (*it)[n] ;
                if (n == N-1) cout << ")";
                else cout << ",";
            }
            cout << "\n";
        }

    return 0;
}