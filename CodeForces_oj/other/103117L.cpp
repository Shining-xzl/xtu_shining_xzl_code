#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int lim = 1e5+3;

int dis[lim][103];
int n,m,q;
vector<int> f[103];
vector<int> son[103];
void bfs(int x)
{
	queue<int> q;
	for (auto v:f[x])
		q.push(v), dis[v][x] = 0;
	int now;
	while(!q.empty())
	{
		now = q.front(); q.pop();
		for (auto v:son[now])
		{
			if (dis[v][x] > n)
			{
				dis[v][x] = dis[now][x] + 1;
				q.push(v);
			}
		}
	}
}
#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	scanf("%d %d %d", &n,&m,&q);
	int x;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &x);
		f[x].push_back(i);
	}
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a,&b);
		son[a].push_back(b);
		son[b].push_back(a);
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1; i <= 100; ++i) bfs(i);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 100; ++j)
			dis[i][j] = Min(dis[i][j],dis[i][j-1]);
	while(q--)
	{
		scanf("%d %d", &a,&b);
		if (dis[a][b] > n) printf("-1\n");
		else printf("%d\n",dis[a][b]);
	}
	return 0;
}