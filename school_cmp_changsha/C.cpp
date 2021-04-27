#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[504][504];
int dis[504][504]; 
int n,q,h[504];
int len[504];

struct cmp
{
	int w,p;
}ans[504][504];;

int find_b(cmp x[],int l,int r,int w)
{
	int mid,ans;
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(x[mid].w <= w)
		{
			ans = x[mid].p;
			l = mid+1;
		}
		else r = mid-1;
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n,&q);
	int x;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		scanf("%d", &h[x]);
	}
	memset(dis,INF,sizeof(dis));
	for(int i = 1; i <= n; ++i)
	{
		dis[i][i] = 0;
		for(int j = i + 1; j <= n; ++j)
		{
			if(h[j] <= h[i]) continue;
			x = (j-i+1) * h[j];
			dis[i][j] = x;
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if(dis[i][k]<INF && dis[k][j] < INF && dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];		
			}
	for (int i = 1; i <= n; ++i)
	{
		len[i] = 1;
		ans[i][1].p = i;
		ans[i][1].w = 0;
		for (int j = i+1; j <= n; ++j)
		{
			while(dis[i][j] <= ans[i][len[i]].w) --len[i];
			++len[i];
			ans[i][len[i]].p = j;
			ans[i][len[i]].w = dis[i][j];
		}
	}
	int a,w,ansx;
	while(q--)
	{
		scanf("%d %d", &a,&w);
		ansx = find_b(ans[a],1,len[a],w);
		printf("%d\n",ansx);
	}
	return 0;
}
