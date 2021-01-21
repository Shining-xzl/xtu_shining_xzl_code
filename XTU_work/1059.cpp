#include <stdio.h>
long long n,a=1;
int i,ans;
int main()
{
	while(scanf("%I64d",&n)==1)
	{
		if(n<0) n=n+(a<<32);
		ans=0;
		for(i=0;i<33;i++)
			if((n&(a<<i))>0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
