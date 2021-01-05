#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 30000 + 5;

vector<int> g[N];
bool used[N];

bool dfs(int u, int fa)
{
	bool has_ring = false;
	used[u] = true;
	for(int v : g[u])
	{
		if(v == fa) continue;
		if(used[v] || dfs(v, u)) has_ring = true;
	}
	return has_ring;
}

int main()
{
	int n, m, a, b, tot = 0, ring = 0;
	memset(used, false, sizeof(used));
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=0; i<n; ++i)
	{
		if(used[i]) continue;
		if(dfs(i, -1)) ++ring;
		++tot;
	}
	printf("%d %d\n", tot, ring);
	return 0;
}
