#include <cstdio>
using namespace std;
typedef long long LL;
const int LIM=1e5+5;
LL sum[LIM];
LL k,Max;
int n,op;

int main()
{
	int time;
	LL x,mul,temp;
	scanf("%d",&time);
	while(time--)
	{
		Max=0;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			sum[i]=sum[i-1]+x;
			if(x>Max)
			{
				Max=x;
				op=i-1;
			}
		}
		if((LL)op>=k)
		{
			printf("NO\n");
		}
		else
		{
			mul=(k-op)/(Max+n-1);
			temp=sum[op]+sum[n]*mul;
			if(temp>=k) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
 } 
