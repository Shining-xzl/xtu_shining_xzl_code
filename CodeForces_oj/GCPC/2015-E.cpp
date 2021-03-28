#include <bits/stdc++.h>
using namespace std;
const int lim=1e4+4;
const int M=2e6+3;
int vis[lim],head[lim],op;
struct link
{
	int son,next;
	int w;
}s[M];
int dis[lim];
int n,m,k;

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(head, -1, sizeof(head));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	op = 0;
}

void add(int a,int b,int w)
{
	++op;
	s[op].son = b;
	s[op].w = w;
	s[op].next = head[a];
	head[a] = op;
}

struct path
{
	int now,dis;
	bool operator < (const path &a) const
	{
		return dis > a.dis;
	}
};

bool spfa()
{
	dis[1] = 0;
	priority_queue<path> q;
	path temp;
	int now,len,i,v,w;
	temp.now = 1;
	temp.dis = 0;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.top(); q.pop();
		now = temp.now;
		len = temp.dis;
		if(dis[now] < len) continue;
		if(now == n && vis[n] == 2)
			return 1;
		i = head[now];
		while(i != -1)
		{
			v = s[i].son;
			w = s[i].w;
			if(len + w < dis[v])
			{
				vis[v] = 1;
				dis[v] = len + w;
				temp.now = v;
				temp.dis = dis[v];
				q.push(temp);
			}
			else if(len + w == dis[v] && vis[v] < 2)
			{
				vis[v]++;
				temp.now = v;
				temp.dis = dis[v];
				q.push(temp);
			}
			i = s[i].next;
		}
	}
	return 0;
}

int main()
{
	int a,b,w;
	while(scanf("%d %d %d",&n,&m,&k) == 3)
	{
		init();
		while(k--) scanf("%*d");
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&w);
			add(a,b,w);
			add(b,a,w);
		}
		if(spfa()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}