#include <cstdio>
#include <cstring>
using namespace std;
int n;
int color[4][45];
int ans;
bool f[45][45][45][45];

void dfs(int a,int b,int c,int d,int state,int now)
{
	if(f[a][b][c][d]) return;
	f[a][b][c][d]=1;
	//if(now>4)
		//printf("%d\n",now);
	if(now>4) return;
	if(a+b+c+d-now>ans)
	{
		//printf("%d\n",now);
		// printf("%d %d %d %d\n",a,b,c,d);
		ans=a+b+c+d-now;
	}
	if(a<n)
	{
		if(state&(1<<color[0][a]))
			dfs(a+1,b,c,d,state^(1<<color[0][a]),now-1);
		else
			dfs(a+1,b,c,d,state|(1<<color[0][a]),now+1);
	}
	if(b<n)
	{
		if(state&(1<<color[1][b]))
			dfs(a,b+1,c,d,state^(1<<color[1][b]),now-1);
		else
			dfs(a,b+1,c,d,state|(1<<color[1][b]),now+1);
	}
	if(c<n)
	{
		if(state&(1<<color[2][c]))
			dfs(a,b,c+1,d,state^(1<<color[2][c]),now-1);
		else
			dfs(a,b,c+1,d,state|(1<<color[2][c]),now+1);
	}
	if(d<n)
	{
		if(state&(1<<color[3][d]))
			dfs(a,b,c,d+1,state^(1<<color[3][d]),now-1);
		else
			dfs(a,b,c,d+1,state|(1<<color[3][d]),now+1);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++)
				scanf("%d",&color[j][i]);
		ans=0;
		memset(f,0,sizeof(f));
		dfs(0,0,0,0,0,0);
		printf("%d\n",ans/2);	
	}
	return 0;
}