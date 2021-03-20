#include <cstdio>
using namespace std;
int n,x;
int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&x);
		int ans=1;
		for(int i=1;i<n;i++)
		{
			if(x&1)
			{
				ans<<=1;
				x=(x+1)>>1;
			}
			else
			{
				ans=ans<<1|1;
				x>>=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
