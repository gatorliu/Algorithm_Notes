// Example program
#include <iostream>
#include <vector>
using namespace std;
// https://lucifer.ren/blog/2019/12/11/LSS/
// 最大連續子序列

int MSS_Math(vector<int> lst) { // 數學解法: 目前MAX = 目前 - 目前最小
int curr = lst[0], mx = lst[0], mn = min(0, curr);; 
    for (int i=1; i< lst.size(); i++) {
        curr += lst[i];
        mx = max(mx, curr-mn);
        mn = min(mn, curr);
    }
    return mx;
}


int MSS_DP(vector<int> lst) {
     //   Q(x) = Max( Q(x-1) + lst[x], lst[x])
     vector<int> dp(lst.size(), 0);
     int mx = dp[0] = lst[0];
     for (int i=1; i<lst.size(); i++) {
         dp[i] = max(dp[i-1]+lst[i], lst[i]);
         if (dp[i]> mx) mx = dp[i];
     }
     return mx;
 
}



int main()
{
    /*
    对于数组 [1, -2, 3, 5, -3, 2], 应该返回 3 + 5 = 8
    对于数组 [0, -2, 3, 5, -1, 2], 应该返回 3 + 5 + -1 + 2 = 9
    对于数组 [-9, -2, -3, -5, -3]  -2
    */
    vector<int> s[4]  = { {1, -2, 3, 5, -3, 2}
                        , {0, -2, 3, 5, -1, 2}
                        , {-9, -2, -3, -5, -3}
                        , {1, 1, 1, 1, 1}};
    for (int i=0; i<4; i++)
        cout << MSS_Math(s[i]) << " ";
    cout <<  endl;

    for (int i=0; i<4; i++)
        cout << MSS_DP(s[i]) << " ";
    cout <<  endl;
}