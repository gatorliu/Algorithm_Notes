// https://tioj.ck.tp.edu.tw/problems/2189
// #include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

/*
用DFS，每個節點要做兩件事:
    1. 回傳所有子樹最長與第二長的值 (參考 PathMax2Wiught 的處理)
    2. 計算所有子樹中，任一子節點到任ㄧ子節點的路徑值，再取最大兩個(參考calAns)
    例如:  
        root 有三個子節點分別回傳 (12, 1) (12, 3), (5, 4)    則最大是 24(12+12), 次大是21(12+9)
        root 有三個子節點分別回傳 (12, 1) (12, 10), (5, 4)   則最大是 24(12+12), 次大是22(12+10)
*/

typedef long long ll;
#define f first
#define s second

const int MN = 1e5+7;
 
int N;
vector< pair<int, int> > island[MN];
vector< pair<ll, ll> > PathMax2Wiught; // 紀錄sub-tree 的 max and second weight of path
vector<bool> used;

ll ans1=0, ans2=0;


void calAns(vector <pair<ll, ll> > V) {
    // 最大值一定是2個最大回傳值的和
    // 次大值，只可能是前2名的組合
    vector<pair<ll, ll > > Vf(2, {0,0}); // 紀錄return值 first 最大的2個
    vector< pair<ll, ll > > Vs(2, {0,0}); // 紀錄return值 second 最大的2個
    
    // 分別找出(first, second)可能的2名
    for(auto p: V) {
        // cout << "p= " << p.f  << ", " << p.s << endl;
        pair<ll, ll> tmp;
        for (int i=0; i<2; i++) {
            if (p.f >= Vf[i].f) {
                tmp = Vf[i];
                Vf[i] = p;
                p = tmp ;
            }
        }
        //cout << "Vf=>"; for (int i=0; i<3; i++)  cout << Vf[i].f  << " "; cout << endl;

        for (int i=0; i<2; i++) {
            if (p.s >= Vs[i].s) {
                tmp = Vs[i];
                Vs[i] = p;
                p = tmp ;
            }
        }
    }
    
    // 計算所有可能 weight
    vector<ll> Vmx;    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            if (i !=j) {
                Vmx.push_back( Vf[i].f + Vf[j].f);
                Vmx.push_back( Vf[i].f + Vf[j].s);
                Vmx.push_back( Vf[i].s + Vf[j].f);
                Vmx.push_back( Vf[i].s + Vf[j].s);
            }
            Vmx.push_back( Vf[i].f + Vs[j].f);
            Vmx.push_back( Vf[i].f + Vs[j].s);
            Vmx.push_back( Vf[i].s + Vs[j].f);
            Vmx.push_back( Vf[i].s + Vs[j].s);
        }
    }
    // cout << "Vmx=>" << Vmx.size() << endl; for (auto a: Vmx)  cout << a  << " "; cout << endl;


    // 排序，去除重複
    sort(Vmx.begin(), Vmx.end());
    int size =unique(Vmx.begin(), Vmx.end()) - Vmx.begin();
    Vmx.resize(size);
    ll mx = Vmx[size-1];
    if (mx > ans1) swap(mx, ans1);
    if (mx == ans1) mx = -1;
    
    ans2 = max({mx, ans2, Vmx[size-2] });
    // cout << ans1 << " " << ans2 << endl;
}

pair<ll, ll> dfs(int root, int w) {
    used[root] = 1;
    vector <pair<ll, ll> > V;
    vector< ll > retWeight;
    
    bool isEnd = true;
    for (auto node: island[root]) {
        if (used[node.f])  continue;
        isEnd = false;
        auto ret = dfs(node.f, node.s );
        //cout << "node.f, ret(1, 2)" << node.f << ", (" << ret.f << ", "  << ret.s << ")\n";
        V.push_back(ret);
        retWeight.push_back(ret.f);
        retWeight.push_back(ret.s);
    }
    if (isEnd) return {w,0};

    //cout << "root == " << root << "\n";
    calAns(V); 

    used[root] = 0;

    // 排序，去除重複然
    sort(retWeight.begin(), retWeight.end());
    int size =unique(retWeight.begin(), retWeight.end()) - retWeight.begin();
    retWeight.resize(size);
    return {retWeight[size-1]+w, retWeight[size-2]+w};
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    //depth = vector< pair<int, ll> >(N, {0,0});
    used = vector<bool>(N,0);
    
    // input data
    int s, e, w;
    for (int i=0; i<N-1; i++) {
        cin >> s >> e >> w;
        island[s].push_back({e,w});
        island[e].push_back({s,w});    
    }
    /*
    //find root (最多子節點的為root)
    int root=0, nodes=0;
    for (int i=0; i<N; i++) {
        if (island[i].size() > nodes) {
            nodes = island[i].size();
            root = i;
        }
    }
    dfs(root, 0);
    */
    dfs(0, 0);
    cout << ans2 << endl;
    
    return 0;
}