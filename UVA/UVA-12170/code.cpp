#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL inf=0x3f3f3f3f3f3f3f3f;
LL n,d,len;
LL p[20004],height[102];
LL dp[2][20004];

void process()
{
	len=0;
	for(int i=1;i<=n;i++)
		for(int mul=1-n;mul<n;mul++)
			p[len++]=height[i]+d*mul;
	sort(p,p+len);
	len=unique(p,p+len)-p;
}

void work_dp()
{
	int now,pre=0,op;
	for(int i=0;i<len;i++)
		if(p[i]==height[1]) dp[pre][i]=0;
		else dp[pre][i]=inf;
	for(int i=2;i<=n;i++)
	{
		now=!pre;
		op=0;
		for(int j=0;j<len;j++)
		{
			while(op<j&&p[j]-p[op]>d) op++;
			while(op<len-1&&abs(p[op+1]-p[j])<=d&&dp[pre][op+1]<=dp[pre][op]) op++;
			if(dp[pre][op]==inf) dp[now][j]=inf;
			else dp[now][j]=abs(p[j]-height[i])+dp[pre][op];
		}
		pre=now;
	}
	for(int i=0;i<len;i++)
		if(p[i]==height[n])
		{
			op=i;
			break;
		}
	printf("%lld\n",dp[now][op]);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&height[i]);
		if(abs(height[n]-height[1])>(n-1)*d)
			printf("impossible\n");
		else
		{
			process();
			work_dp();
		}
	} 
	return 0;
} 
