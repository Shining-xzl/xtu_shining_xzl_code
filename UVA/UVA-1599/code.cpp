#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
const int lim = 1e5+3;
int head[lim],op;
int dis[lim],n,m;
struct link
{
	int son,next,c;
}s[lim<<2];
int q[lim];
bool vis[lim];

void add(int a,int b,int c)
{
	++op;
	s[op].son = b;
	s[op].c = c;
	s[op].next = head[a];
	head[a] = op;
}

void init()
{
	op = 0;
	memset(head, -1, sizeof(head));
	memset(dis, INF, sizeof(dis));
	memset(vis, 0, sizeof(vis));
}

void bfs()
{
	int l = 1, r = 0, v, i, now;
	dis[n] = 0;
	q[++r] = n;
	while(l <= r)
	{
		now = q[l++];
		i = head[now];
		while(i != -1)
		{
			v = s[i].son;
			if(dis[v] == INF)
			{
				q[++r] = v;
				dis[v] = dis[now] + 1;
			}
			i = s[i].next;
		}
	}
}

pair<int,int> qx[lim];
int ans[lim];
int posx[lim];

void print()
{
	printf("%d\n", dis[1]);
	int l = 1, r = 0, now, v, pos, stand, len = 0;
	qx[++r] = pair<int,int> (1,-1);
	vis[1] = 1;
	posx[1] = 1;
	while(l <= r)
	{
		pos = r;
		stand = 2e9;
		for (int i = l; i <= pos; ++i)
			if(qx[i].second < stand)
				stand = qx[i].second;
		for (int i = l ; i <= pos; ++i)
			if(stand == qx[i].second)
			{
				now = qx[i].first;
				int j = head[now];
				while(j != -1)
				{
					v = s[j].son;
					if(dis[v] + 1 == dis[now] && vis[v] == 0)
					{
						vis[v] = 1;
						qx[++r] = pair<int,int>(v,s[j].c);
						posx[v] = r;
					}
					else if(dis[v] + 1 == dis[now])
					{
						if(s[j].c < qx[posx[v]].second)
							qx[posx[v]].second = s[j].c;
					}
					j = s[j].next;
				}
			}
		ans[len++] = stand;
		l = pos + 1;
	}
	printf("%d", ans[1]);
	for (int i = 2; i < len; ++i)
		printf(" %d", ans[i]);
	printf("\n");
}

int main()
{
	while(scanf("%d %d",&n,&m) == 2)
	{
		init();
		int a,b,c;
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		bfs();
		print();
	}
	return 0;
} 
