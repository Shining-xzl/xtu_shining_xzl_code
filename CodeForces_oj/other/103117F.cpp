#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int lim = 1e4+3;
const int alim = 1e3+3;
int head[alim],op,dis[alim],pre[alim];
int n,m;
int S,T;
int val[alim];

struct edge
{
	int v,flow;
	int next;
}s[lim];

void add(int a,int b,int w)
{
	s[op].v = b; s[op].flow = w; 
	s[op].next = head[a]; head[a] = op++;
	s[op].v = a; s[op].flow = 0; 
	s[op].next = head[b]; head[b] = op++;
}

bool bfs(int S,int T)
{
	memset(dis, 0, sizeof(dis));
	queue<int> q;
	dis[S] = 1;
	q.push(S);
	int now,w,v,i;
	while(!q.empty())
	{
		now = q.front(); q.pop();
		pre[now] = i = head[now];
		while(i != -1)
		{
			v = s[i].v;
			w = s[i].flow;
			if (dis[v] == 0 && w)
			{
				dis[v] = dis[now] + 1;
				q.push(v); 
			}
			i = s[i].next;
		}
	}
	return dis[T] > 0;
}
#define Min(x,y) ((x)<(y)?(x):(y))
int dfs_dinic(int now,int flow)
{
	if (now == T) return flow;
	int i = pre[now],w,v,rest = flow;
	while(i != -1 && rest)
	{
		v = s[i].v;
		w = s[i].flow;
		if (w && dis[v] == dis[now] + 1)
		{
			w = dfs_dinic(v,Min(w,rest));
			rest -= w;
			s[i].flow -= w;
			s[i^1].flow += w;
			if (w == 0) dis[v] = 0;
		}
		i = s[i].next;
	}
	pre[now] = i;
	return flow - rest;
}

void work()
{
	int res = 0;
	while(bfs(S,T)) 
	{
		res += dfs_dinic(S,500);
	}
	printf("%d\n", m-res);
	for (int i = 0; i < m*4; i += 4) // 边的顺序4个为一组
	{
		if (s[i].flow == 0) putchar('1');
		else putchar('0');
	}
	putchar('\n');
}

void init()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	op = 0;
	int a,b;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &a,&b); // 一条边与两个点建边
		add(i+n,a,1);
		add(i+n,b,1);
	}
	S = 0; T = n+m+1;
	for (int i = 1; i <= n; ++i) 
		add(i,T,val[i]);
	for (int i = 1; i <= m; ++i)
		add(S,i+n,1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		work();
	}
	return 0;
}