#include<cstdio>
#include<map>
#include<set>
using namespace std;
const int N = 100000 + 5;

int x[N], y[N], tag[N*2]={0}, rhash[N*2];

int main()
{
	int m, n, k, i, idx, bg, ed, ans=0;
	map<int, int> mp;
	set<int> st;
	
	idx = 0;
	scanf("%d%d%d", &m, &n, &k);
	
	for(i=0; i<n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		st.insert(x[i]);
		st.insert(y[i]);
		st.insert(y[i]+1);
	}
	
	for(int p : st)
	{
		mp[p] = ++idx;
		rhash[idx] = p;
	}
	
	for(i=0; i<n; ++i)
	{
		++tag[mp[x[i]]];
		--tag[mp[y[i]+1]];
	}
	for(i=1; i<=idx; ++i) tag[i]+=tag[i-1];
	i=1;
	while(i<=idx)
	{
		while(i<=idx && tag[i]<k) ++i;
		if(i>idx) break;
		bg=i;
		while(i<=idx && tag[i]>=k)
		{
			ed=i;
			++i;
		}
		if(i>idx) break;
		ans+=rhash[ed]-rhash[bg]+1;
	}
	printf("%d\n", ans);
	return 0;
}
