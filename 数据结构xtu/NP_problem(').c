#include <stdio.h>
#include <string.h>
int n,m;
int f[100][100];
int vis[100];
#define Min(x,y) ((x)<(y)?(x):(y))

int check(int now)
{
	memset(vis,0,sizeof(vis));
	int i;
	int res = 0,temp,j,minf,ST = now;
	printf("%d ",now);
	for (i = 1; i < n; ++i)
	{
		temp = 1e9;
		minf = -1;
		for (j = 1; j <= n; ++j)
		{
			if (j != ST && vis[j] == 0 && f[now][j] < temp)
			{
				minf = j;
				temp = f[now][j];
			} 
		}
		if (minf == -1) return 1e9;
		res += temp;
		vis[minf] = 1;
		now = minf;
		printf("-> (%d) -> %d ",temp,minf);
	}
	printf("-> (%d) -> %d ",f[minf][ST],ST);
	res += f[minf][ST];
	return res;
}

int main()
{
	scanf("%d %d",&n,&m);
	memset(f,0x3f,sizeof(f));
	int a,b,c,i;
	while(m--)
	{
		scanf("%d %d %d",&a,&b,&c);
		f[a][b] = f[b][a] = c;
	}
	int ans = 1e9,t;
	for (i = 1; i <= n; ++i)
	{
		t = check(i);
		ans = Min(ans,t);
		printf(" len of this path : %d\n",t);
	}
	printf("Min_len = %d\n",ans);
	return 0;
} 
/*
5 10
1 2 1 
1 3 2
1 4 7
1 5 5
2 3 4
2 4 4
2 5 3
3 4 1
3 5 2
4 5 3

*/
