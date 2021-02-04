#include <cstdio>
using namespace std;
long long a,b,x,y,n,ans;
long long ax,bx,temp;

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		ans=1e+18;
		scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&n);
		if(n>=a+b-x-y) ans=x*y;
		else
		{
			ax=a-n;
			bx=b;
			if(ax<x)
			{
				bx-=(x-ax);
				ax=x;
			}
			temp=ax*bx;
			if(temp<ans) ans=temp;
			bx=b-n;
			ax=a;
			if(bx<y)
			{
				ax-=(y-bx);
				bx=y;
			}
			temp=ax*bx;
			if(temp<ans) ans=temp;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
