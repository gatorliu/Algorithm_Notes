// https://zerojudge.tw/ShowProblem?problemid=f630

/* 使用SET 會 TLE
  先做 size排序後
    sort(FD.begin(), FD.end(), [](set<int> va, set<int> vb){ return va.size() <vb.size() ;});
    NA (score:82%)

    未做: NA (score:42%)
*/


// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>

typedef long long ll;


using namespace std;
int N;
vector< set<int> >FD;

bool with_comm_friend(set<int> &va, set<int> &vb) {
    for (auto a: va) {
        if ( vb.find(a) != vb.end())  {
            return true;
        }
    }
    return false;
}
ll solve(){
    ll cnt =0;
    sort(FD.begin(), FD.end(), [](set<int> va, set<int> vb){ return va.size() <vb.size() ;});
    for(int f1=0; f1 < N; f1++) {
        for (int f2=f1+1; f2 < N; f2++ ) {
            cnt += with_comm_friend(FD[f1], FD[f2]) ? 1: 0;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    int n, f;
    // input
    for (int i=0; i<N; i++) {
        cin >> n;
        FD.push_back({});
        while(n--){
            cin >> f;
            FD[i].insert(f);
        }
    }

    cout << solve() << endl;
    return 0;
}