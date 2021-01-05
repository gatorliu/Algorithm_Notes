#include <iostream>
#include <algorithm>
#include <vector>
const int N = 10000 + 5;
using namespace std;

int n, m, h[N];  
vector<int> g[N];

int cnt = 0;  // 紀錄最長路徑總數
int curr_steps = 0; // 目前走了幾步(當前路徑步數)
int max_steps = 0;  // 走到終點(n)的步數(最長路徑)
void dfs(int u)
{
    if ( u == n ) { // 走到終點(n)
        if (curr_steps > max_steps) { // 如果發現新的最長路徑
            max_steps = curr_steps;
            cnt = 1;            
        } else if (curr_steps == max_steps) { // 如果當前路徑步數 == 最長路徑
            ++cnt;
        } 
        return;
    } 
	for (auto v : g[u] ) {
        curr_steps++; // 當前路徑步數 +1
        dfs(v);
        curr_steps--; // 當前路徑步數 -1
    }
}

int main()
{
	cin >> n >> m;
	for(int i=1; i<=n; ++i)cin >> h[i];
	for(int i=1; i<=m; ++i)
	{
		int a, b;
		cin >> a >> b;
		if(h[a] > h[b]) g[a].push_back(b);
		else if(h[a] < h[b]) g[b].push_back(a);
	}

	dfs(1);
	cout << cnt << endl;
	return 0;
}