//最大流算法 dinic
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define Min(x,y) ((x)<(y)?(x):(y))
struct edge
{
	int son,w,next;
}s[4003];
int head[203],ure[203],op,dis[203];
int n,m,x;

void add(int a,int b,int w)
{
	s[op].son = b;
	s[op].w = w;
	s[op].next = head[a];
	head[a] = op++;
}

bool bfs(int S,int T) // 分层图
{
	memset(dis, 0, sizeof(dis));
	dis[S] = 1;
	queue<int> q;
	q.push(S);
	int now,v,i;
	while(!q.empty())
	{
		now = q.front(); q.pop();
		ure[now] = i = head[now]; // 更新
		while(i != -1)
		{
			v = s[i].son;
			if(dis[v] == 0 && s[i].w)
			{
				dis[v] = dis[now] + 1;
				q.push(v);
			}
			i = s[i].next;
		}
	}
	return dis[T] != 0;
}

int dfs(int S,int flow) // 增广路
{
	if(S == n) return flow;
	int rest = flow;
	int i = ure[S],v,w;
	while(i != -1 && rest)
	{
		v = s[i].son;
		w = s[i].w;
		if(w && dis[v] == dis[S] + 1)
		{
			w = dfs(v,Min(w,rest));
			if(w == 0) dis[v] = 0; // 优化2
			rest -= w;
			s[i].w -= w;
			s[i^1].w += w;
		}
		i = s[i].next;
	}
	ure[S] = i; // 优化1
	return flow - rest;
}

int main()
{
	scanf("%d %d %d", &n,&m,&x);
	int a,b,w;
	memset(head, -1, sizeof(head));
	while(m--)
	{
		scanf("%d %d %d", &a,&b,&w);
		add(a,b,w);
		add(b,a,0);
	}
	int Max_flow = 0;
	while(bfs(1,n)) Max_flow += dfs(1,1e9);
	if(Max_flow == 0) printf("Orz Ni Jinan Saint Cow!\n");
	else printf("%d %d\n", Max_flow, x % Max_flow == 0 ? x / Max_flow : x / Max_flow + 1);
	return 0;
}