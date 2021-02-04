#include <cstdio>
#include <queue>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
	int time,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&x);
		int l=1,r=10000,mid,ans=-1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(mid*(mid+1)/2==x)
			{
				ans=mid;
				break;
			}
			else if(mid*(mid+1)/2<x) l=mid+1;
			else r=mid-1;
		}	
		while(l*(l+1)/2<x) l++;
		if(ans==-1)
		{
			ans=l;
			if(l*(l+1)/2-x<2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}