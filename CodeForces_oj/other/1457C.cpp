#include <cstdio>

using namespace std;
int dp[100003];
char s[100003];

int main()
{
//	freopen("in.txt","r",stdin);
	int temp,time,n,p,k,x,y,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d%s%d%d",&n,&p,&k,s+1,&x,&y);
		for(int i=n;i>0;i--)
		{
			if(s[i]=='1')
			{
				if(i+k>n) dp[i]=0;
				else dp[i]=dp[i+k];
			}
			else
			{
				if(i+k>n) dp[i]=1;
				else dp[i]=dp[i+k]+1;
			}
		}
		ans=2e+9;
		for(int i=1;n-i>=p-1;i++)
		{
			temp=(i-1)*y+dp[i+p-1]*x;
			if(temp<ans) ans=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}