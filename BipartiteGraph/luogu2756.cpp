/*
匈牙利算法
*/
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int match[103];
struct edge
{
	int son;
	int next;
}s[2508];
int head[103],op = 1;
bool vis[103];

void add(int a,int b)
{
	s[op].son = b;
	s[op].next = head[a];
	head[a] = op++;
}

bool dfs(int now)
{
	int i = head[now],v;
	while(i != -1)
	{
		v = s[i].son;
		if(vis[v] == 0)
		{
			vis[v] = 1;
			if(match[v] == 0 || dfs(match[v]))
			{
				match[v] = now;
				return 1;
			}
		}
		i = s[i].next;
	}
	return 0;
}

int main()
{
	scanf("%d %d", &m,&n);
	int u,v;
	memset(head, -1, sizeof(head));
	while(scanf("%d %d", &u,&v) == 2)
	{
		if(u == v && u == -1) break;
		add(u,v);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) ++ans;
	}
	printf("%d\n", ans);
	for (int i = m+1; i <= n; ++i)
	{
		if(match[i] != 0) printf("%d %d\n", match[i],i);
	}
	return 0;
}