// https://zerojudge.tw/ShowProblem?problemid=932
// #include <bits/stdc++.h>
/*
 * reference: 
 * https://openhome.cc/Gossip/AlgorithmGossip/SeparateNumber.htm
 * http://puremonkey2010.blogspot.com/2011/09/algorithm-in-java.html
 * 
 * F(n) = \Sigme_{} f(n-x,x) 
 *      where:
 *          x = 0 ~ n
 *          f(x, y) = f(x-y, min((x-y), y));
 *              where
 *                  f(1, y)= f(x, 1)= f(0, y) = f(y, 0)=1
*/
#include <iostream>
using namespace std;
typedef long long ll;

int dp[102][60] ={0};

int f(int x, int y) {
    if (dp[x][y] != 0)  return dp[x][y];
    else if ( x<=1 || y<=1 ) {dp[x][y]=1; return 1;}

    int sum = 0;
    for(int i=y; i>=1; i--){
        //cout <<  "\tf("  << x << ", " << y-i << ")"<<endl;
        sum += f(x-i, min(x-i, i));
    }    
    dp[x][y]=sum;
    return sum;
}

ll F(int n){
    ll sum=0;
    for (int y=1; y<=n; y++) {
        // cout <<  " f("  << n-y << ", " << min((n-y), y) << ")" << endl;
        ll ans = f(n-y, min((n-y), y));
        // cout << "\t\t = " << ans << endl;
        sum += ans;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    if (n<=3) cout << n << endl;
    else cout << F(n) << endl;

    return 0;
}