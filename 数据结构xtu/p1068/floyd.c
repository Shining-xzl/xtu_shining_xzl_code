#include <stdio.h>
#include <string.h>
#define lim 3005

int path[lim][lim];
int n,m;

int floyd(int S,int T)
{
	int i,j,k;
	for (i = 1; i <= n; ++i)
		path[i][i] = 0;
	for (k = 1; k <= n; ++k)
	{
		for (i = 1; i <= n; ++i)
		{
			if(path[i][k] > 1e9) continue;
			for (j = 1; j <= n; ++j)
			{
				if(path[k][j] < 1e9 && path[i][k] + path[k][j] < path[i][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}
	if(path[S][T] > 1e9) return -1;
	else return path[S][T];
}

#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	int a,b,c;
	scanf("%d %d", &n,&m);
	memset(path, 0x3f, sizeof(path));
	while(m--)
	{
		scanf("%d %d %d", &a,&b,&c);
		path[a][b] = path[b][a] = Min(c,path[a][b]);
	}
	printf("%d\n", floyd(1,n));
	return 0;
}
