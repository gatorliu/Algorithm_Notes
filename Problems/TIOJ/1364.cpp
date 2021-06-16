// https://tioj.ck.tp.edu.tw/problems/1364
// #include <bits/stdc++.h>
#include <iostream>

#include <algorithm>
#include <utility>
#include <queue>

using namespace std;


typedef long long ll;
int n, k;
// ll arr[1000000+5];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    /* O(NlogN)
    while(cin >> n) {
        cin >> k;
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n, [](ll a, ll b){return a>b;});
        cout << arr[k-1] << '\n';
    }
    */
    // O(N) : using priority_queue
    ll num;
    while(cin >> n) {
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll> > que;
        for (int i=0; i<n; i++) {
            cin >> num;
            if (que.size() < k ) que.push(num);
            else if (num > que.top() ) {
                que.pop();
                que.push(num);
            }
        }
        cout << que.top() << '\n';
    }
    return 0;
}