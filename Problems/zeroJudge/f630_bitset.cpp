// https://zerojudge.tw/ShowProblem?problemid=f630
// TLE 解
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <bitset>
#include <vector>

// TLE : NA (score:70%)
using namespace std;
typedef long long ll;
const int MAX_N = 1000000; 
int N;
vector< bitset<MAX_N> >FD;
/*
bool have_comm_friend(bitset<MAX_N> a, bitset<MAX_N> vb) {
  return (a & b).any();
}*/
ll solve(){
    ll cnt =0;
    for(int f1=0; f1 < N; f1++) {
        for (int f2=f1+1; f2 < N; f2++ ) {
            //cout << "f1= " << f1 << " f2=" << f2 << endl;
            if((FD[f1] & FD[f2]).any() ) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    int n, f;
    // input
    bitset<MAX_N> bstemp;
    for (int i=0; i<N; i++) {
        cin >> n;
        FD.push_back(bstemp);
        while(n--){
            cin >> f;
            FD[i][f] = true;
        }
        //sort(FD[i].begin(), FD[i].end());
    }

    cout << solve() << endl;
    return 0;
}