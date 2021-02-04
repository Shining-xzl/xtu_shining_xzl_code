#include <cstdio>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	int n,pre,ans,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		scanf("%d",&pre);
		ans=1;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&x);
			if(x>=pre) ans++;
			if(x==pre) x++;
			if(x>pre)pre=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}