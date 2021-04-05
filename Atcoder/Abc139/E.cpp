/*
题目大意：
n*(n-1)/2场比赛，内部存在一定的次序，至少需要多少天，
很明显的top排序
边的top排序
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int lim = 1003;
int schedule[lim][lim];
int n,id[lim][lim];
bool vis[lim][lim];
int degree[lim * lim],dis[lim * lim];
int id_node = 0;
vector<int> son[lim * lim];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d", &n);
	int x;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < n; ++j)
		{
			scanf("%d",&x);
			schedule[i][j] = x;
			if(!vis[x][i])
			{
				vis[x][i] = vis[i][x] = 1;
				id[i][x] = id[x][i] = (++id_node);
				// printf("%d %d : %d\n",i,x,id_node);
			}
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 2; j < n; ++j)
		{
			son[id[i][schedule[i][j-1]]].push_back(id[i][schedule[i][j]]);
			// printf("%d: %d \n", id[i][schedule[i][j-1]],id[i][schedule[i][j]]);
			++degree[id[i][schedule[i][j]]];
		}
	queue<int> q;
	for (int i = 1; i <= id_node; ++i)
		if(degree[i] == 0)
			q.push(i),dis[i] = 1;
	int ans = 0,len,v;
	id_node -= q.size();
	while(!q.empty())
	{
		x = q.front(); q.pop();
		if(dis[x] > ans) ans = dis[x];
		len = son[x].size();
		for (int i = 0; i < len; ++i)
		{
			v = son[x][i];
			if(degree[v])
			{
				--degree[v];
				if(degree[v] == 0)
				{
					q.push(v);
					dis[v] = dis[x] + 1;
					--id_node;
				}
			}
		}
	}
	// printf("%d\n", id_node);
	if(id_node) ans = -1;
	printf("%d\n", ans);
	return 0;
}