#include <cstdio>
using namespace std;
typedef long long LL;

int n;
LL s[100003];
LL max,ans,sum;

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		max=0;
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
			sum+=s[i];
			if(max<s[i])
				max=s[i];
		}
		ans=max*(LL)(n-1)-sum;
		if(ans<0) 
		{
			if(ans%(n-1)!=0)
				ans=ans%(n-1)+n-1;
			else ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}