#include <cstdio>
#include <cstring>
using namespace std;
char s[53];
int map[103][103];
int n,m;
int ans[103][103],allans;

int point[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int x,int y)
{
	if(x<1||x>n||y<1||y>m) return;
	if(ans[x][y]>0) return;
	ans[x][y]=1;
	int tempx,tempy;
	for(int i=0;i<4;i++)
	{
		tempx=x+point[i][0];
		tempy=y+point[i][1];
		if(map[tempx][tempy]<map[x][y])
		{
			dfs(tempx,tempy);
			if(ans[tempx][tempy]+1>ans[x][y])
				ans[x][y]=ans[tempx][tempy]+1;
		}
	}
	if(ans[x][y]>allans)
		allans=ans[x][y];
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%d%d",s,&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&map[i][j]);
		memset(ans,0,sizeof(ans));
		allans=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dfs(i,j);
		printf("%s: %d\n",s,allans);
	}
	return 0;
}