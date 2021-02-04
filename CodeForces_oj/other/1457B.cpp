#include <cstdio>
#include <cstring>
using namespace std;
int c[100004];
int num[100004];
int dp[102][100004];
bool isc[102];

int main()
{
	freopen("in.txt","r",stdin);
	int time,n,k,ans;
	scanf("%d",&time);
	while(time--)
	{
		memset(isc,0,sizeof(isc));
		ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			isc[c[i]]=1;
			if(c[i]==c[i-1])
				num[i]=num[i-1]+1;
			else num[i]=1;
			//printf("%d ",num[i]);
			
		}
		//printf("\n");
		for(int i=1;i<=100;i++)
		{
			if(!isc[i]) continue;
			for(int j=1;j<=k;j++)
			{
				if(c[j]==i&&num[j]==j)
					dp[i][j]=0;
				else dp[i][j]=1;
			}
			for(int j=k+1;j<=n;j++)
			{
				if(c[j]==i)
				{
					dp[i][j]=dp[i][j-num[j]];
					if(num[j]>=k&&dp[i][j]>dp[i][j-k])
						dp[i][j]=dp[i][j-k];
				}
				else dp[i][j]=dp[i][j-k]+1;
			}
		}
		for(int i=1;i<=100;i++)
			if(isc[i]&&dp[i][n]<ans)
				ans=dp[i][n];
		printf("%d\n",ans);

	}
	return 0;
}