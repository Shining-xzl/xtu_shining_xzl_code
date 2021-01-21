#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int time,x;
	int ans[20],len;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&x);
		len=0;
		if(x==0)
		{
			len=1;
			ans[1]=0;
		}
		while(x>0)
		{
			ans[++len]=x%3;
			x/=3;	
		}
		for(x=1;x<len;x++)
		{
			if(ans[x]>1)
			{
				ans[x]-=3;
				ans[x+1]+=1;
			}
		}
		if(ans[len]>1)
		{
			ans[len]-=3;
			ans[++len]=1;
		}
		for(x=len;x>0;x--)
		{
			if(ans[x]<0) printf("-");
			else printf("%d",ans[x]);
		}
		printf("\n");
	}
	return 0;
}
