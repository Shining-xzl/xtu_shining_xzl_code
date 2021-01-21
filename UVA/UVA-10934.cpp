#include <cstdio>

using namespace std;
typedef long long LL;

LL dp[102][66];

void get_ans_dp()//dp方程用二分思维推导
{
	for(int i=1;i<=100;i++)
		for(int j=1;j<=63;j++)
			dp[i][j]=1+dp[i-1][j-1]+dp[i][j-1];
}

int main()
{
	int k,ans;
	LL n;
	get_ans_dp();
	while(scanf("%d%lld",&k,&n)==2)
	{
		if(k==0) break;
		ans=0;
		for(int i=1;i<=63;i++)
			if(dp[k][i]>=n)
			{
				ans=i;
				break;
			}
		if(ans==0) printf("More than 63 trials needed.\n");
		else printf("%d\n",ans);
	}
	return 0;
}