#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 30000 + 5;

vector<int> g[N];
bool used[N];
int deg[N]={0};

void dfs(int u, int &node, int &edges)
{
	used[u] = true;
	++node;
	edges += deg[u];
	for(int v : g[u])
	{
		if(used[v]) continue;
		dfs(v, node, edges);
	}
	return;
}

int main()
{
	int n, m, a, b, tot = 0, graph = 0;
	int node, edges;
	memset(used, false, sizeof(used));
	scanf("%d%d", &n, &m);
	
	for(int i=0; i<m; ++i)
	{
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		if(a<b) ++deg[a];
		else ++deg[b];
	}
	for(int i=0; i<n; ++i)
	{
		if(used[i]) continue;
		node = edges = 0;
		dfs(i, node, edges);
		if(node != edges+1) ++graph;
		++tot;
	}
	printf("%d %d\n", tot, graph);
	return 0;
}
