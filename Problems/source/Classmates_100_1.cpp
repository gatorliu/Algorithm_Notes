#include<iostream>
//#include<cstring>
#include<vector>
using namespace std;
const int N = 30000 + 5;

vector<int> g[N];
bool used[N];

void dfs_group_only(int u) //只計算有幾組
{
	used[u] = true;
	for(int v : g[u])
	{
		if(used[v]) continue;
		dfs_group_only(v);
	}
}

bool dfs(int u, int p) // p = 前面的朋友(parent)
{
	bool has_ring =  false;
	used[u] = true;
	for(int v : g[u])
	{
		if (v==p) continue; // 不可省略， 否則 has_ring == true
		if (used[v] || dfs(v, u)) has_ring = true; 
		//  只要碰到used[v] == true，一定　has_ring 
		// 	因為不同群，一定不可能在 g[u]，所以為不存在之前找過，卻在不同群的問題
	}
	return has_ring;
}

int main()
{
	int n, m, a, b, tot = 0, ring = 0;
	memset(used, false, sizeof(used)); // 設定都是 false
	cin >> n >> m ;
	for(int i=0; i<m; ++i)
	{
		cin >> a >> b ;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//*  只計算有幾組
	for(int i=0; i<n; ++i)
	{
		if(used[i]) continue;
		dfs_group_only(i);
		++tot;
	}
	cout << " Group only: " << tot << endl;
	memset(used, false, sizeof(used)); // 設定都是 false
	tot = 0;

	for(int i=0; i<n; ++i)
	{
		if(used[i]) continue;
		if( dfs(i, -1) ) ring++ ;
		++tot;
	}
	cout << tot << " " << ring <<  endl;

	return 0;
}
