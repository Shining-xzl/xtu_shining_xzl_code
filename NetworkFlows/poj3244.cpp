/*
K取方格 费用流
拆点建图
将点一分为二，中间建流量边（访问标记）
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int elim = 1e5+3;
const int alim = 1e4+3;
const int inf = 0x3f3f3f3f;
int op,S,N,K,T;
int head[alim],dis[alim],flow[alim],pre[alim],a[alim];
bool vis[alim];
#define Min(x,y) ((x)<(y)?(x):(y))
#define Max(x,y) ((x)>(y)?(x):(y))

struct edge
{
	int v,flow,cost;
	int next;
}s[elim];

void add(int a,int b,int w,int cost)
{
	s[op].v = b; s[op].flow = w; s[op].cost = cost;
	s[op].next = head[a]; head[a] = op++;
	s[op].v = a; s[op].flow = 0; s[op].cost = -cost;
	s[op].next = head[b]; head[b] = op++;
}

bool spfa(int S,int T)
{
	memset(dis, -inf, sizeof(dis));
	memset(flow, 0, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	int now,i,v,w;
	dis[S] = 0; flow[S] = inf;
	q.push(S);
	while (!q.empty())
	{
		now = q.front(); q.pop();
		vis[now] = 0;
		i = head[now];
		while (i != -1)
		{
			v = s[i].v;
			w = s[i].flow;
			if (w && dis[v] < dis[now] + s[i].cost)
			{
				dis[v] = dis[now] + s[i].cost;
				flow[v] = Min(w,flow[now]); 
				pre[v] = i;
				if (vis[v] == 0) q.push(v), vis[v] = 1;
			}
			i = s[i].next;
		} 
	}
	return flow[T] > 0;
}

int EK(int S,int T)
{
	int res = 0, i, mflow;
	while(spfa(S,T))
	{
		mflow = flow[T];
		res += mflow * dis[T];
		i = T;
		while(i != S)
		{
			s[pre[i]].flow -= mflow;
			s[pre[i]^1].flow += mflow;
			i = s[pre[i]^1].v;
		}
	}
	return res;
}

void init()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &N,&K);
	int sum = N*N,now;
	S = 0; T = sum * 2 + 1;
	for (int i = 1; i <= sum; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			now = i * N + j;
			add(now,now+sum,1,a[now]);
			add(now,now+sum,inf,0);
			if (j < N)
				add(now+sum,now+1,inf,0);
			if (i < N-1)
				add(now+sum,now+N,inf,0);
		}
	add(S,1,inf,0);
	add(sum+sum,T,K,0);
}


int main()
{
	init();
	printf("%d\n",EK(S,T));
	return 0;
}
