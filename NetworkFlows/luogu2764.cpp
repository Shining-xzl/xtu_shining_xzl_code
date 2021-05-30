/*
最大流处理最小点覆盖
拆点匹配，n - 最大匹配 = 最小点覆盖
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int elim = 1e5+3;
const int alim = 404;
const int inf = 1e9;
int head[alim],pre[alim],dis[alim];
int op = 0,n,m,S,T;
bool vis[alim];

struct edge
{
	int v,flow;
	int next;
}s[elim];

void add(int a,int b,int flow)
{
	s[op].v = b; s[op].flow = flow;
	s[op].next = head[a]; head[a] = op++;
	s[op].v = a; s[op].flow = 0; 
	s[op].next = head[b]; head[b] = op++;
}

bool bfs()
{
	memset(dis, 0, sizeof(dis));
	queue<int> q;
	int v,now,w,i;
	dis[S] = 1;
	q.push(S);
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
	int rest = flow,i,v,w;
	i = pre[now];
	while(i != -1 && rest)
	{
		v = s[i].v;
		w = s[i].flow;
		if (dis[v] == dis[now] + 1 && w)
		{
			w = dfs_dinic(v,Min(rest,w));
			s[i].flow -= w;
			s[i^1].flow += w;
			rest -= w;
			if (w == 0) dis[v] = 0;
		}
		pre[now] = i;
		i = s[i].next;
	}
	return flow - rest;
}

void init()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n,&m);
	int a,b;
	S = 0;
	T = n*2 + 1;
	for (int i = 1; i <= n; ++i)
		add(S,i,1), add(i+n,T,1);
	while(m--)
	{
		scanf("%d %d", &a,&b);
		add(a,b+n,1);
	}
	int Max_flow = 0;
	while(bfs()) Max_flow += dfs_dinic(S,inf);
	printf("%d\n", n-Max_flow);
}

int main()
{
	init();
	return 0;
}