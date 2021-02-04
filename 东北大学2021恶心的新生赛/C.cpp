#include <cstdio>
using namespace std;
typedef long long LL;
LL ans=0ll,num=0ll;
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	int pre=-1,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>=pre)
		{
			num++;
		}
		else num=1;
		pre=x;
		ans+=num;
	}
	printf("%lld\n",ans);
	return 0;
 } 
