// Example program
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 最大遞增子序列

int LLS(vector<int> lst, bool increase_only= true) { 
    vector<int> DP;
    for(int v : lst) {
        int idx;
        if ( increase_only) 
            idx = lower_bound(DP.begin(), DP.end(), v ) - DP.begin();
        else
            idx = upper_bound(DP.begin(), DP.end(), v ) - DP.begin();
            

        if ( idx ==  DP.size()) {
            DP.push_back(v);
        } else {
            DP[idx] = v;
        }
    }
    return DP.size();
}


int main()
{
    
    vector<int> s[5]  = { {1, -2, 3, 5, -3, 2}
                        , {0, -2, 3, 5, -1, 2}
                        , {-9, -2, -3, -5, -3}
                        , {1, 1, 1, 1, 1}
                        , {2,1,6,3,5,4,8,7,7,9}};
    
    cout << "不遞減數列個數:" << endl;
    for (int i=0; i<5; i++)
        cout << LLS(s[i], false) << " ";
    cout <<  endl;

    cout << "遞增數列個數:" << endl;
    for (int i=0; i<5; i++)
        cout << LLS(s[i], true) << " ";
    cout <<  endl;
}