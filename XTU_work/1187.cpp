#include <cstdio>
using namespace std;

int main()
{
	__int64 n,ans,a,b,c;
	while(scanf("%I64d",&n)==1)
	{
		if(n==0) break;
		a=n/3;
		if(n%3==1) 
		{
			b=a+1;
			c=a;
		}
		else if(n%3==2)
		{
			b=a+1;
			c=a+1;
		}
		else
		{
			b=a;
			c=a;
		}
		ans=a*(a-1)*(a-2)/6;
		ans%=1000000007;
		ans+=b*(b-1)*(b-2)/6;
		ans%=1000000007;
		ans+=c*(c-1)*(c-2)/6;
		ans%=1000000007;
		ans+=a*b*c;
		ans%=1000000007;
		printf("%I64d\n",ans);
	}
	return 0;
}
