#include <cstdio>
#include <cstring>
using namespace std;
const int LIM=1e4+3;
const int INF=0x3f3f3f3f;

int dp[2][LIM][2];//滚动数组 
int s[LIM],d[LIM],n;

int Min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&s[i],&d[i]);
		int pre=1,now=0;
		memset(dp,INF,sizeof(dp));
		for(int i=n;i>0;i--)
		{	
			now^=1;
			pre^=1;
			dp[now][i][1]=dp[now][i][0]=0;//now代表i到j，pre代表i+1到j，区间dp 
			for(int j=i+1;j<=n;j++)
			{
				dp[now][j][0]=Min(dp[pre][j][1]+s[j]-s[i],dp[pre][j][0]+s[i+1]-s[i]);//直接赋值免去了初始化的麻烦 
				if(dp[now][j][0]>=d[i]) dp[now][j][0]=INF;//判断是否可以取到，有坑，必须用 >= 
				dp[now][j][1]=Min(dp[now][j-1][0]+s[j]-s[i],dp[now][j-1][1]+s[j]-s[j-1]);
				if(dp[now][j][1]>=d[j]) dp[now][j][1]=INF;
			}
		}
		if(dp[now][n][0]>dp[now][n][1])
			dp[now][n][0]=dp[now][n][1];
		if(dp[now][n][0]==INF)
			printf("No solution\n");
		else printf("%d\n",dp[now][n][0]);
	}
	return 0;
} 
