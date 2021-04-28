#include <stdio.h>

#define Max(x,y) ((x)>(y)?(x):(y))

int ans = 0;

int Lson[1003],Rson[1003];

void dfs(int now,int count)
{
	if(now == -1) return;
	++count;
	ans = Max(ans,count);
	dfs(Lson[now],count);
	dfs(Rson[now],count);
}

int main()
{
	int i,n,x;
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		scanf("%d %d",&Lson[x],&Rson[x]);
	}
	if(n > 0)
		dfs(0,0);	
	printf("%d\n",ans);
	return 0;
}
