#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
int num[200003];
int q[200003],len;
 
int main()
{
freopen("in.txt","r",stdin);
	int time,n,x;
	long long ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		len=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(!num[x])
				q[++len]=x;
			num[x]++;
		}
		ans=0;
		for(int i=1;i<=len;i++)
		{
			x=q[i];
			if(x>2)
				ans+=(LL)num[x]*(LL)num[x-1]*(LL)num[x-2];
			ans+=(LL)num[x]*(LL)(num[x]-1)*(LL)(num[x]-2)/6;
			if(x>2)
				ans+=(LL)num[x]*(LL)(num[x]-1)*(LL)num[x-2]/2;
			ans+=(LL)num[x]*(LL)(num[x]-1)*(LL)num[x+2]/2;
			if(x>1)
				ans+=(LL)num[x]*(LL)(num[x]-1)*(LL)num[x-1]/2;
			ans+=(LL)num[x]*(LL)(num[x]-1)*(LL)num[x+1]/2;
		}
		for(int i=1;i<=len;i++)
		{
			x=q[i];
			num[x]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}