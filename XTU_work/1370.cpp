#include <cstdio>
#include <cstring>
using namespace std;
int n,m;

bool edgel[103][103],edger[103][103];

int q[103];
bool vis[103];

bool check(int now)
{
	memset(vis,0,sizeof(vis));
	int num = 0,l = 0,x;
	q[num] = now;
	vis[now] = 1;
	while(l <= num)
	{
		x = q[l++];
		for (int i = 1; i <= n; ++i)
			if (edgel[x][i] && vis[i] == 0)
			{
				q[++num] = i;
				vis[i] = 1;
			}
	}
	if (num != n/2) return 0;
	num = 0;
	l = 0;
	q[num] = now;
	vis[now] = 1;
	while(l <= num)
	{
		x = q[l++];
		for (int i = 1; i <= n; ++i)
			if (edger[x][i] && vis[i] == 0)
			{
				q[++num] = i;
				vis[i] = 1;
			}
	}
	return num == n/2;
}

int get()
{
	for (int i = 1; i <= n; ++i)
		if (check(i)) 
			return i;
	return 0;
}


int main()
{
	int T,a,b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n,&m);
		memset(edgel, 0, sizeof(edgel));
		memset(edger, 0, sizeof(edger));
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &a,&b);
			edgel[a][b] = 1;
			edger[b][a] = 1;
		}
		printf("%d\n",get());
	}
	return 0;
}