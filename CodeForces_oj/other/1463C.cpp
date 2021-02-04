#include <cstdio>

using namespace std;

long long abs(long long a)
{
	if(a<0) a=-a;
	return a;
}
long long t[100003],x[100003];
int main()
{
	freopen("in.txt","r",stdin);
	int time,n,ans;
	long long nowtime,nextx,nowx,prex;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		ans=0;
		nowtime=0;
		nowx=0;
		nextx=0;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&t[i],&x[i]);
		t[n+1]=1e12;
		for(int i=1;i<=n;i++)
		{	
			prex=nowx;
			if(t[i]>=nowtime)
			{
				nowtime=t[i]+abs(nextx-x[i]);
				nextx=x[i];
			}
			if(nextx>nowx)
			{
				nowx+=t[i+1]-t[i];
				if(nowx>nextx) nowx=nextx;
			}
			else
			{
				nowx-=t[i+1]-t[i];
				if(nowx<nextx) nowx=nextx;
			}
			if((prex<=x[i]&&x[i]<=nowx)||(prex>=x[i]&&x[i]>=nowx)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}