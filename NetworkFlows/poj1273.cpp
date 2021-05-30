#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int inf = 2e9+3;
const int lim = 204;
int head[lim],dis[lim],op,pre[lim];
int n,m;
struct edge
{
	int v,flow;
	int next;
}s[lim<<1];

void add(int a,int b,int f)
{
	s[op].v = b; s[op].flow = f;
	s[op].next = head[a]; head[a] = op++;
	s[op].v = a; s[op].flow = 0;
	s[op].next = head[b]; head[b] = op++;
}

void init()
{
	memset(head, -1, sizeof(head));
	op = 0;
	int a,b,c;
	while(m--)
	{
		scanf("%d %d %d", &a,&b,&c);
		add(a,b,c);
	}
}

bool bfs(int S,int T)
{
	memset(dis,0,sizeof(dis));
	dis[S] = 1;
	queue<int> q;
	int now,v,i,w;
	q.push(S);
	while(!q.empty())
	{
		now = q.front(); q.pop();
		pre[now] = i = head[now];
		while(i != -1)
		{
			v = s[i].v;
			w = s[i].flow;
			if (w && dis[v] == 0)
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

int get_flow(int now,int T,int flow)
{
	if (now == T) return flow;
	int rest = flow;
	int i,w,v;
	i = pre[now];
	while(i != -1 && rest)
	{
		v = s[i].v;
		w = s[i].flow;
		if (w && dis[v] == dis[now] + 1)
		{
			w = get_flow(v,T,Min(w,rest));
			s[i].flow -= w;
			s[i^1].flow += w;
			rest -= w;
			if (w == 0) dis[v] = 0; 
		}
		i = s[i].next;
	}
	pre[now] = i;
	return flow - rest;
}

int dinic(int S,int T)
{
	int res = 0;
	while(bfs(S,T)) res += get_flow(S,T,inf);
	return res;
}

int main()
{
	while(scanf("%d %d", &m,&n) == 2)
	{
		init();
		printf("%d\n",dinic(1,n));
	}
	return 0;
}
