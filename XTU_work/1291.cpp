#include <cstdio>
#include <algorithm>
using namespace std;
int s[1003];
int sum[1003];

int main()
{
	int i,time,n,m,min,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		sort(s+1,s+n+1);
		min=1e+9;
		for(i=1;i<=n;i++)
			sum[i]=sum[i-1]+s[i];
		for(i=m;i<=n;i++)
		{
			if(s[i]-s[i-m+1]<min)
			{
				min=s[i]-s[i-m+1];
				ans=sum[i]-sum[i-m];
			}
		}
		printf("%d %d\n",min,ans);
	}
	return 0;
}
