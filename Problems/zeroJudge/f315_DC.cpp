// https://zerojudge.tw/ShowProblem?problemid=f315
// #include <bits/stdc++.h>

/* 
更精簡的寫法，參考：
    https://github.com/algo-seacow/code/blob/master/apcs/10910/p4_merge_sort.cpp
    https://github.com/algo-seacow/code/blob/master/apcs/10910/p4_DC.cpp
*/

/*----------------------------------------------------------------
解題想法:
    利用分治法，或是說Merge Sort 將數字排序
    Merge過程中，如果數字在 `右半`則需要計算： 

        1: 如果數字是第一次出現　則減去作伴已經排序數字
        2: 如果數字是第二次出現　則加上作伴已經排序數字
        Ex: 
        1 2 3 5 5    1 2 3 4 4 
        遇到第一個　1:  -0 (1)   左1　排　右1 後
        遇到第二個　2:  +1 (1)     => 2 的左邊有1個比其小的數
        遇到第二個　3:  +2 (1,2)   => 3 的左邊有2個比其小的數
        遇到第一個　4:  -3 (1,2,3) => 4 的左邊有3個比其小的數
        遇到第二個　4:  +3 (1,2,3) => 4 的左邊有3個比其小的數 (與前面互相抵銷)
*/

#include <iostream>

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef vector< int > vi;
typedef vector< pair<int, int> > vp;
typedef long long ll;

#define F first
#define S second

int N, N2;
vi Flag;
vp V;

ll sum=0;
void MergeSort(int L, int R) { // 分治法 Divide And Conquer
    //cout << L  << ", " << R << endl;
    if (L==R) return;
    
    
    // Divide
    int Mid= (L+R)/2;
    MergeSort(L, Mid);
    MergeSort(Mid+1, R);

    // Conquer
    int sz=R-L+1;
    vp Tmp(sz);
    int i=L, j=Mid+1, k=0;
    while ( i<=Mid && j<=R ) {
        if (V[i].F < V[j].F) {  // 注意: 這裡不要用 <=    排序後會是 (1,1), (1,-1) , .........
            Tmp[k++] = V[i++];
        } else {
            // 計算sum
            sum += (i-L) * V[j].S;
            // cout << L << ", " << R <<  " : "  << (i-L) * V[j].S << " " << sum << endl;
            
            Tmp[k++] = V[j++];
        }
    }
    while( i<=Mid ) {
        Tmp[k++] = V[i++];
    }
    while( j<=R ) {
        // 計算sum
        sum += (i-L) * V[j].S;
        // cout << L << ", " << R <<  " : "  << (i-L) * V[j].S << " " << sum << endl;   
        Tmp[k++] = V[j++];
    }

    for (int i=0; i<sz; i++) {
        V[L+i] = Tmp[i];
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;   Flag = vi(N+1,0);
    N2= N*2;       V = vp(N2, {0,-1});
    
    for (auto &v : V) {
        cin >> v.F;
        if (Flag[v.F] == 0)
            Flag[v.F]  = 1;     
        else 
            v.S = 1;
    }
    //for (auto n: V) cout << "(" << n.F << "," << n.S << ") "; cout << endl;
    MergeSort(0, N2-1);
    cout << sum << endl;
    //for (auto n: V) cout << "(" << n.F << "," << n.S << ") "; cout << endl;
    return 0;
}