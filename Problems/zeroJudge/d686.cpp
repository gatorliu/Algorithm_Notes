// https://zerojudge.tw/ShowProblem?problemid=d686
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Cutting Sticks
*/

int L, N;
int C[51];
int DP[1001][1001];

int cutting_sticks(int index, int l, int r) {
    if (index <0 || index >= N) return 0;
    if (C[index] <=l || C[index] >= r) return 0;
    if (DP[l][r] !=-1) return DP[l][r];
    //cout << index << ", " << l << ", " <<  r << ", " << DP[l][r] <<  endl;
   
    // 試試 切
    int sum_cut_r =  cutting_sticks(index+1, C[index], r); //右邊

    // 左邊先要算出從哪切
    int l_index= 0;
    while(1) {
        if ( C[l_index] > l || l_index==N) break;
        l_index++;
    }
    int sum_cut_l = cutting_sticks(l_index, l, C[index]); //左邊
    int sum_cut = (r - l) + sum_cut_l + sum_cut_r;

    // 試試 不切
    int sum_no_cut=0;
    //if (C[index-1]>=l || C[index+1]<=r) {  // 超過一個，才需要試
        sum_no_cut = cutting_sticks(index+1, l, r);
    //}


    // 決定到底切不切
    int sum;
    if (sum_cut == 0) sum= sum_no_cut;
    else if (sum_no_cut == 0) sum= sum_cut;
    else sum = min(sum_cut, sum_no_cut);
    //cout << "sum :"  << sum<< endl;
    DP[l][r] = sum;
    return sum;
}

int main() {
   

    while(cin >> L >> N) {
	// init
        for(int i=0; i<=L ; i++)
            for(int j=0; j<=L ; j++)
                DP[i][j] = -1;

        for(int i=0; i<N ; i++) {
            cin >> C[i];
        }        
       cout << "The minimum cutting is "<<cutting_sticks(0, 0, L) << ".\n";

       
    }
}
