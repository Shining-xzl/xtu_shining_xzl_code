#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f;
int k,n;
LL s[5004];
LL dp[2][5004];

inline LL Min(LL a,LL b)
{
	return a<b?a:b; 
}

inline LL get(int a,int b)
{
	return (s[b]-s[a])*(s[b]-s[a]);
}

void core_dp()
{
	int now,pre=0;
	memset(dp[0],0,sizeof(dp)); 
	for(int i=1;i<=k;i++)
	{
		now=(!pre);
		memset(dp[now],INF,sizeof(dp[now]));
		for(int j=2;j<=n;j++)
		{
			dp[now][j]=dp[now][j-1];
			if(n-j>(k-i)*3)
				dp[now][j]=Min(dp[now][j],dp[pre][j-2]+get(j,j-1));
		}
		pre=now;
	}
	printf("%lld\n",dp[now][n]);
}

int main()
{
	int time;
	scanf("%d",&time);
	memset(dp,INF,sizeof(dp));
	while(time--)
	{
		scanf("%d%d",&k,&n);
		k+=8;
		for(int i=1;i<=n;i++)
			scanf("%lld",&s[i]);
		core_dp();
	} 
	return 0;
} 
