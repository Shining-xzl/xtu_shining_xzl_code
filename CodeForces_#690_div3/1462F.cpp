#include <cstdio>
#include <algorithm>
using namespace std;
const int LIM=2e5+3;
int n;
int xl[LIM],xr[LIM];
int q1[LIM],q2[LIM];

int main()
{
//	freopen("in.txt","r",stdin);
	int time,ans,temp,now;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&xl[i],&xr[i]);
			q1[i]=xr[i];
			q2[i]=xl[i];
		}
		sort(q1+1,q1+n+1);
		sort(q2+1,q2+n+1);
		ans=n;
		for(int i=1;i<=n;i++)
		{
			temp=lower_bound(q1+1,q1+n+1,xl[i])-q1-1;
			now=temp;
			temp=upper_bound(q2+1,q2+n+1,xr[i])-q2;
			if(q2[temp]>xr[i]) temp--;
			else temp=n;
			now+=(n-temp);
			if(now<ans) ans=now;

		}
		printf("%d\n",ans);
	}
	return 0;
}