#include <cstdio>
#include <cstring>
using namespace std;

int x,s[100004];

int main()
{
//	freopen("in.txt","r",stdin);
	int time,n,k,x,ans,sum;
	scanf("%d",&time);
	while(time--)
	{
		ans=-1;
		sum=0;
		memset(s,-1,sizeof(s));
		s[0]=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&x);
			sum+=x;
			sum%=k;
			if(s[sum]!=-1&&i-s[sum]>ans) ans=i-s[sum];
			if(s[sum]==-1) s[sum]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
 } 
