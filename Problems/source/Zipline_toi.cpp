#include<cstdio>
#include<algorithm>
#include<vector>
const int N = 10000 + 5;
using namespace std;

int n, m, h[N];
int cnt[N]={0};	  // counter : 從 index 到 n 點的最長路徑總數  
int dis[N];		  // distance: 從 index 到 n 點的最長路徑	
int used[N]={0};  // 紀錄是否已經算過 1 :算過
vector<int> g[N];

void dfs(int u)
{
	if(used[u]) return;
	dis[u] = 0;				// init dis[] = 0，應該可以不在這邊做(定義時 int dis[N] = {0};)
	if(u == n)				// 走到終點
	{
		cnt[u] = 1;					// 將終點count設定為 1，應該可以在 initial 時設定 cnt[n]=1;
		used[u] = 1;				// 將終點設為used, 應該可以不做此步驟，或是在 initial 時設定 used[n]=1;
		return;
	}
	for(int v : g[u])		// 遍歷所有 child nodes 
	{
		dfs(v);
		dis[u] = max(dis[u], dis[v]);	// 如果發現更長路徑，就存起來
	}
	
	for(int v : g[u])		// 再遍歷所有 child nodes，以便累加處理**最長路徑總數**
	{
		if(dis[u] == dis[v])			// 如果發現subtree最長路徑 == 本身最長路徑(因為還沒加 1，所以用 等於)
		{								// 表示此子路徑(the path of the subtree)是 真正的最長路徑
			cnt[u] += cnt[v];			// 其最長路徑總數，就要累加上去
		}
	}
	dis[u] += 1;			// subtree都算完了，最長路徑加一個
	used[u] = 1;			// subtree都算完了，設為used
}

int main()
{
	scanf_s("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf_s("%d", &h[i]);
	for(int i=0; i<m; ++i)
	{
		int a, b;
		scanf_s("%d%d", &a, &b);
		if(h[a] > h[b]) g[a].push_back(b);
		else if(h[a] < h[b]) g[b].push_back(a);
	}
	dfs(1);
	printf("%d\n", cnt[1]);
	return 0;
}