#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[2103][2103];
int n,sum[78];
struct book
{
	int h,w;
	bool operator < (const book &a) const 
	{
		return h>a.h;
	}
}s[73];

int Min(int a,int b) {return a<b?a:b;} 
int Max(int a,int b) {return a>b?a:b;} 

int main()
{
	int time,h2,h1;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&s[i].h,&s[i].w);
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+s[i].w;
		memset(dp,INF,sizeof(dp));
		dp[0][0]=s[1].h;
		for(int i=2;i<=n;i++)
		{
			h1=sum[i]-sum[1];
			for(int j=h1;j>=0;j--)
			{
				h2=h1-j;
				for(int k=h2;k>=0;k--)
				{
					if(j>s[i].w) dp[j][k]=Min(dp[j][k],dp[j-s[i].w][k]);
					if(j==s[i].w) dp[j][k]=Min(dp[j][k],dp[0][k]+s[i].h);
					if(k>s[i].w) dp[j][k]=Min(dp[j][k],dp[j][k-s[i].w]);
					if(k==s[i].w) dp[j][k]=Min(dp[j][k],dp[j][0]+s[i].h);
				}
			}
		}
		int ans=INF;
		for(int j=sum[n]-sum[1];j>0;j--)
			for(int k=sum[n]-sum[1];k>0;k--)
				if(dp[j][k]<=900)
				ans=Min(ans,dp[j][k]*Max(Max(sum[n]-j-k,j),k));
		printf("%d\n",ans);
	}
	return 0;
} 
