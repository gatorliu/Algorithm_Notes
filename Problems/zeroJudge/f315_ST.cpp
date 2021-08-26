// https://zerojudge.tw/ShowProblem?problemid=f315
// #include <bits/stdc++.h>

/* 
更優化的寫法，參考：
    https://github.com/algo-seacow/code/blob/master/apcs/10910/p4.cpp   BIT
*/

/*----------------------------------------------------------------
線段樹解題想法:
一個空的線段數，然後從數字最小的開始插入 (先右　後左)
每個節點紀錄其左邊有多少數字
例如：
1 2 1 2 
插入右2時，右邊是1共2個
插入左2時，右邊是1共1個
答案即是　2-1=1


PS: Add時，如果能同時query, 會更好。但沒有想到要怎麼實做
*/

#include <iostream>

#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector< ll > vll;
typedef vector< pair<int, int> > vp;


#define F first
#define S second

int N, N2;
vp V; 
vll ST;
ll sum=0;

void add(int L, int R, int idx, int pos){ // pos : idx in V ,  idx: idx in ST
    if (L == R) {
        ST[idx] = 1;
        return ;
    }

    int Mid = (L+R)/2;
    int idx2 = idx*2;
    if (pos <= Mid) add(L,   Mid,  idx2, pos);
    else            add(Mid+1, R, idx2+1, pos);

    ST[idx] = ST[idx2] + ST[idx2+1];
}

ll query(int L, int R, int l, int r, int idx){ // l : left in Query
    if (L == l && R == r) {
        return ST[idx];
    }

    int Mid = (L+R)/2;
    int idx2= idx*2;
    if (r <= Mid)  // all left
        return query(L, Mid, l, r,  idx2);
    else if ( l > Mid)
        return query(Mid+1, R,  l, r,  idx2+1);
    else
        return (
                query( L,   Mid,     l, Mid,  idx2)
            +   query( Mid+1, R, Mid+1,   r,   idx2+1)
        );
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;   V = vp(N+1, {0,0});
    N2= N*2;       ST = vll(N2*4, 0);
    
    int v;
    for (int i=1; i<=N2; i++) {
        cin >> v;
        if (V[v].F == 0)    V[v].F = i;     
        else                V[v].S = i;     
    }

    for (int i=1; i<=N; i++) {
        
        add(1, N2, 1, V[i].S);
        //for (auto st: ST) cout << st << " "; cout << endl;
        //cout << i<< "(" << V[i].S  << "): "<< query(1, N2, 1, V[i].S, 1) << endl;
        sum += ( query(1, N2, 1, V[i].S, 1) - 1); //這裡-1 是減掉自己 (其實可以省掉-1, 因為加減相互抵銷)
        
        
        add(1, N2, 1, V[i].F);
        //for (auto st: ST) cout << st << " "; cout << endl;
        //cout << i<< "(" << V[i].F  << "): "<< query(1, N2, 1, V[i].F, 1)  << endl;
        sum -= ( query(1, N2, 1, V[i].F, 1) - 1 );
        
    }
    //for (auto st: ST) cout << st << " "; cout << endl;
    cout << sum << '\n';
    return 0;
}