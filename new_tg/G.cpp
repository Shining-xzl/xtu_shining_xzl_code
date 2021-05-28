#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int lim = 8004, alim = 507;
const int inf = 0x3f3f3f3f;
typedef long long LL;

struct edge
{
	int v;
	int fc,cost;
	int next;
}s[lim];

int head[alim],op = 0;
int S,T,num[alim],sum;
int dis[alim],pre[alim],fc[alim];
bool vis[alim];
long long ans;

void add(int a,int b,int fc,int cost)
{
	s[op].v = b;
	s[op].fc = fc;
	s[op].cost = cost;
	s[op].next = head[a];
	head[a] = op++;
}

bool init()
{
	int n,m,a,b,c,tot = 0;
	memset(head, -1, sizeof(head));
	op = 0; ans = 0LL;
	sum = 0;
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &num[i]);
		tot += num[i];
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &a,&b,&c);
		add(a,b,inf,c);
		add(b,a,0,-c);
		add(b,a,inf,c);
		add(a,b,0,-c);
	}
	if (tot % n != 0) return 0;
	S = 0; T = n+1;
	tot /= n;
	for (int i = 1; i <= n; ++i)
	{
		if (num[i] > tot)
		{
			add(S,i,num[i]-tot,0);
			add(i,S,0,0);
			sum += num[i]-tot;
		}
		else if (num[i] < tot)
		{
			add(i,T,tot-num[i],0);
			add(T,i,0,0);
		}
	}
	return 1;
}

#define Min(x,y) ((x)<(y)?(x):(y))

bool spfa()
{
	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(fc, 0, sizeof(fc));
	int v,i,now;
	queue<int> q;
	dis[S] = 0;
	fc[S] = inf;
	q.push(S);
	while(!q.empty())
	{
		now = q.front(); q.pop();
		vis[now] = 0;
		i = head[now];
		while(i != -1)
		{
			v = s[i].v;
			if (s[i].fc && dis[v] > dis[now] + s[i].cost)
			{
				dis[v] = dis[now] + s[i].cost;
				fc[v] = Min(fc[now],s[i].fc);
				pre[v] = i;
				if (vis[v] == 0) q.push(v), vis[v] = 1; 
			}
			i = s[i].next;
		}
	}
	return fc[T] > 0;
}

int EK()
{
	ans += (LL)fc[T] * (LL)dis[T];
	int i = T, fcT = fc[T];
	while(i != S)
	{
		s[pre[i]].fc -= fcT;
		s[pre[i]^1].fc += fcT;
		i = s[pre[i]^1].v;	
	}
	return fcT;
}

bool solve()
{
	int Max_flow = 0;
	while(spfa()) Max_flow += EK();
	return Max_flow == sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		if(init() && solve()) printf("%lld\n", ans);
		else printf("-1\n");
	}
	return 0;
}