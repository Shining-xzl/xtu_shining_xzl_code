/*
关键在于建图，拆点
一天分为早上，晚上，早上连接汇点，晚上连接源点（以num[i]的容量0费用，等效于早上的餐巾用完后留到晚上）
其他的字面意思建边即可
费用流
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;
const int lim = 1e5+4;
const LL inf = 1e15;
struct edge
{
	LL cost,flow;
	int son,next;
}s[lim];
LL p,m,f,n,sx;
LL num[2003],ans = 0ll;
int head[4009],N,op = 0;
int S,T;

void add(int a,int b,LL f,LL cost)
{
	s[op].son = b;
	s[op].flow = f;
	s[op].cost = cost;
	s[op].next = head[a];
	head[a] = op++;

	s[op].son = a;
	s[op].flow = 0;
	s[op].cost = -cost;
	s[op].next = head[b];
	head[b] = op++;
}

void init()
{
	memset(head, -1, sizeof(head));
	scanf("%d", &N);
	S = 0;
	T = N * 2 + 1;
	for (int i = 1; i <= N; ++i)
		scanf("%lld", &num[i]);
	scanf("%lld %lld %lld %lld %lld", &p,&m,&f,&n,&sx);
	for (int i = 1; i <= N; ++i)
	{
		add(S,i,inf,p);
		add(i,T,num[i],0);
		add(S,i+N,num[i],0);
		if (i + m <= N) add(i+N,i+m,inf,f);
		if (i + n <= N) add(i+N,i+n,inf,sx);
		if (i + 1 <= N) add(i+N,i+N+1,inf,0);
	}
}
LL dis[4009];
LL fc[4009];
bool vis[4009];
int  pre[4009];

#define Min(x,y) ((x)<(y)?(x):(y))

bool spfa()
{
	memset(vis, 0, sizeof(vis));
	memset(fc, 0, sizeof(fc));
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	dis[S] = 0;
	fc[S] = inf;
	q.push(S);
	int now,v,i;
	while(!q.empty())
	{
		now = q.front(); q.pop();
		vis[now] = 0;
		i = head[now];
		while(i != -1)
		{
			v = s[i].son;
			if (s[i].flow && dis[v] > dis[now] + s[i].cost)
			{
				dis[v] = dis[now] + s[i].cost;
				fc[v] = Min(s[i].flow,fc[now]);
				pre[v] = i;
				if (!vis[v]) vis[v] = 1 , q.push(v);
			}
			i = s[i].next;
		}
	}
	return fc[T] > 0;
}

void EK()
{
	ans += dis[T] * fc[T];
	int i = T;
	while(i != S)
	{
		s[pre[i]].flow -= fc[T];
		s[pre[i]^1].flow += fc[T];
		i = s[pre[i]^1].son;
	}
}

void work()
{
	while(spfa()) EK();
	printf("%lld\n", ans);
}

int main()
{
	init();
	work();
	return 0;
}