#include <stdio.h>
#include <string.h>

#define lim 3000
int n,m;
struct edge
{
	int v,w,next;	
}s[lim<<1];
int dis[lim],head[lim],op = 0,vis[lim];

void add(int a,int b,int c)
{
	s[op].v = b;
	s[op].w = c;
	s[op].next = head[a];
	head[a] = op++;
}

int dij(int S,int T)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[S] = 0;
	int i,v,j,now,Max;
	for (i = 0; i < n; ++i)
	{
		Max = 1e9;
		now = -1;
		for (j = 1; j <= n; ++j)
			if(vis[j] == 0 && dis[j] < Max)
				now = j, Max = dis[j];
		if(now == -1) break;
		vis[now] = 1;
		j = head[now];
		while(j != -1)
		{
			v = s[j].v;
			if (dis[v] > dis[now] + s[j].w)
				dis[v] = dis[now] + s[j].w;
			j = s[j].next;
		}
	}
	if(dis[T] > 1e9) return -1;
	else return dis[T];
}

int main()
{
	scanf("%d %d", &n,&m);
	int a,b,c;
	memset(head, -1, sizeof(head));
	while(m--)
	{
		scanf("%d %d %d", &a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	printf("%d\n", dij(1,n));
	return 0;
}