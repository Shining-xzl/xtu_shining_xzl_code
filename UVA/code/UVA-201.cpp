#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int k[12][12][2];
int ans[12];
int con=0;

void work()
{
	if(con) printf("\n**********************************\n\n");
	printf("Problem #%d\n\n",++con);
	memset(k,0,sizeof(k));
	memset(ans,0,sizeof(ans));
	char s[2];
	int x,y;
	bool flag=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='H') k[x][y+1][0]=1;
		else k[y+1][x][1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(k[i][j][0]!=0)
				k[i][j][0]+=k[i][j-1][0];
		}
		for(int j=1;j<=n;j++)
			if(k[i][j][1]!=0)
				k[i][j][1]+=k[i-1][j][1];
	}
	// for (int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		printf("%d(%d) ",k[i][j][0],k[i][j][1]);
	// 	}
	// 	printf("\n");
	// }
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int l=1;i+l<=n&&j+l<=n;l++)
			{
				
				if(k[i+l][j][1]>=l&&k[i][j+l][0]>=l&&k[i+l][j+l][0]>=l&&k[i+l][j+l][1]>=l)
					ans[l]++,flag=1;
			}
	if(flag)
	{
		for(int i=1;i<=n;i++)
			if(ans[i])
				printf("%d square (s) of size %d\n",ans[i],i);
	}
	else printf("No completed squares can be found.\n");
}

int main()
{
	// freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)==2)
		work();
	return 0;
}