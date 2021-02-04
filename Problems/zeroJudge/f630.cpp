// https://zerojudge.tw/ShowProblem?problemid=f630

// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>

typedef long long ll;


using namespace std;
int N;
vector< vector<int> >FD;

bool find(int a, vector<int> &vb) { 
    int s = 0, e = vb.size()-1;
    int i;
    while(s<=e) {
        //cout <<s << " " << e << endl;
        i= (s+e)/2;
        if (vb[i]==a) return true;
        else if (vb[i] > a) e = i-1;
        else s=i+1;   
    }
    
    return false;
}

bool with_comm_friend(vector<int> &va, vector<int> &vb) {
    for (auto a: va) {
        if (find(a, vb)) return true;
    }
    return false;
}
ll solve(){
    ll cnt =0;
    //sort(FD.begin(), FD.end(), [](vector<int> va, vector<int> vb){ return va.size() <vb.size() ;});
    for(int f1=0; f1 < N; f1++) {
        for (int f2=f1+1; f2 < N; f2++ ) {
            //cout << "f1= " << f1 << " f2=" << f2 << endl;
            if (with_comm_friend(FD[f1], FD[f2])) cnt++;
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
            FD[i].push_back(f);
        }
        sort(FD[i].begin(), FD[i].end());
    }

    cout << solve() << endl;
    return 0;
}