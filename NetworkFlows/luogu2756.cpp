/*
网络流找最大匹配
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int lim = 106;

struct edge
{
	int v,next,w;
}s[lim*lim];

int head[lim],op,pre[lim];
int n,m;
int S,T;
int dis[lim];

void add(int a,int b,int w)
{
	s[op].v = b;
	s[op].w = w;
	s[op].next = head[a];
	head[a] = op++;
}

void init()
{
	memset(head, -1, sizeof(head));
	int u,v;
	scanf("%d %d", &m,&n);
	while(scanf("%d %d", &u,&v) == 2)
	{
		if (u == v && u == -1) break;
		add(u,v,1);
		add(v,u,0);
	}
	// 构建源点，汇点，建立完整网络
	S = 0;
	T = n+1;
	for (int i = 1; i <= m; ++i)
	{
		add(S,i,1);
		add(i,S,0);
	}
	for (int i = m+1; i <= n; ++i)
	{
		add(i,T,1);
		add(T,i,0);
	}
}

bool bfs(int S,int T) // 构建层次图
{
	memset(dis, 0, sizeof(dis));
	queue<int> q;
	int i,v,now;
	dis[S] = 1;
	q.push(S);
	while(!q.empty())
	{
		now = q.front(); q.pop();
		pre[now] = i = head[now];
		while(i != -1)
		{
			v = s[i].v;
			if (s[i].w && dis[v] == 0)
			{
				dis[v] = dis[now] + 1;
				q.push(v);
			}
			i = s[i].next;
		}
	}
	return dis[T] != 0;
}

#define Min(x,y) ((x)<(y)?(x):(y))

int dfs(int now,int flow) // 找最大流
{
	if(now == T) return flow;
	int rest = flow,i,v,w;
	i = pre[now];
	while(i != -1 && rest)
	{
		v = s[i].v;
		w = s[i].w;
		if(w && dis[v] == dis[now] + 1)
		{
			w = dfs(v,Min(rest,w));
			if (w == 0) dis[v] = 0; // 无增广路
			s[i].w -= w;
			s[i^1].w += w; // 关键点，防止阻塞
			rest -= w;
		}
		i = s[i].next;
	}
	pre[now] = i; // 当前弧优化
	return flow - rest;
}

void work()
{
	int Max_flow = 0,j,v;
	while(bfs(S,T)) Max_flow += dfs(S,lim);
	printf("%d\n", Max_flow);
	for (int i = 1; i <= m; ++i)
	{
		j = head[i];
		while(j != -1)
		{
			v = s[j].v;
			if(s[j].w == 0 && v > m)
			{
				printf("%d %d\n", i,v);
				break;
			}
			j = s[j].next;
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}