#include <cstdio>
using namespace std;

int main()
{
	int time,n,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		if(n==1) ans=0;
		else if(n==2) ans=1;
		else if(n==3) ans=2;
		else if((n&1)==0) ans=2;
		else ans=3;
		printf("%d\n",ans);
	}
	return 0;
}