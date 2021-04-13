#include <stdio.h>
int n,a=1;
int i,ans;
int main()
{
	while(scanf("%d",&n)==1)
	{
		ans=0;
		for(i = 0; i < 32; ++i)
			if((n&(1<<i)) != 0) 
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
