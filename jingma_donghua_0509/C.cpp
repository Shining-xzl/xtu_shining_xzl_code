#include <cstdio>
#include <cstring>
using namespace std;
bool ans = 0;
int n,m;
bool p[1003][1003];
bool v[1003][1003];
bool vis[1003];

void dfs(int now)
{
	if(vis[now])
	{
		ans = 1;
		return;
	}
	vis[now] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if(!ans && p[now][i] && !v[now][i])
		{
			v[now][i] = v[i][now] = 1;
			dfs(i);
		}
	}
}

int main()
{
	int a,b;
	while(scanf("%d %d", &n,&m) == 2)
	{
		memset(p,0,sizeof(p));
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		ans = 0;
		while(m--)
		{
			scanf("%d %d",&a,&b);
			p[a][b] = p[b][a] = 1;
		}
		for (int i = 1; i <= n; ++i)
		{
			if(!ans && !vis[i])
				dfs(i);
		}
		if(ans) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}