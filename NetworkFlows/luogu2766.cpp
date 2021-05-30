#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int lim = 506;
int a[lim];
int dp[lim];
int n;

struct edge
{
	int v,flow;
	int next;
}s[lim*lim*4];
int S,T;
int head[lim<<1],op = 0;
int pre[lim<<1],dis[lim<<1];
#define Max(x,y) ((x)>(y)?(x):(y))

int process()
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = 1;
		for (int j = 1; j < i; ++j)
			if (a[j] <= a[i])
				dp[i] = Max(dp[i],dp[j]+1);
		ans = Max(ans,dp[i]);
	}
	return ans;
}

void add(int a,int b,int flow)
{
	s[op].v = b;
	s[op].flow = flow;
	s[op].next = head[a];
	head[a] = op++;
	s[op].v = a;
	s[op].flow = 0;
	s[op].next = head[b];
	head[b] = op++;
}

bool bfs(int S,int T)
{
	memset(dis, 0, sizeof(dis));
	dis[S] = 1;
	queue<int> q;
	int i,v,w,now;
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
	return dis[T] != 0;
}

#define Min(x,y) ((x)<(y)?(x):(y))

int dfs(int now,int flow)
{
	if (now == T) return flow;
	int rest = flow;
	int i = pre[now],v,w;
	while(i != -1 && rest)
	{
		v = s[i].v;
		w = s[i].flow;
		if (dis[v] == dis[now] + 1)
		{
			w = dfs(v,Min(w,rest));
			if (w == 0) dis[v] = 0;
			rest -= w;
			s[i].flow -= w;
			s[i^1].flow += w;
		}
		i = s[i].next;
	}
	pre[now] = i;
	return flow - rest;
}

int dinic()
{
	int res = 0;
	while(bfs(S,T)) 
	{
		res += dfs(S,1e9);
	}
	return res;
}

void work(int MAX)
{
	memset(head, -1, sizeof(head));
	int Xa,Xb;
	S = 0; T = n*2+1;
	for (int i = 1; i <= n; ++i)
	{
		Xa = i; Xb = i + n;
		add(Xa,Xb,1);
		if (dp[i] == 1) add(S,Xa,1);
		if (dp[i] == MAX) add(Xb,T,1);
		for (int j = i+1; j <= n; ++j)
			if (a[i] <= a[j] && dp[i] + 1 == dp[j])
				add(Xb,j,1);
	}
	int ans = dinic();
	printf("%d\n",ans);
	add(S,1,504);
	add(1,1+n,504);
	add(n,n+n,504);
	if (dp[n] == MAX)
		add(n+n,T,504);
	ans += dinic();
	if (n == 1) ans = 1; // 特判
	printf("%d\n",ans);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int ans = process();
	printf("%d\n",ans);
	work(ans);
	return 0;
}