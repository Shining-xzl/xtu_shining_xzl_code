#include <stdio.h>
using namespace std;

int main()
{
	int time;
	int n,m,i;
	__int64 temp,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		temp=0;
		for(i=1;i<n;i++)
			temp=(temp<<3)+(temp<<1)+9;
		ans=temp/(long long)m;
		temp=(temp<<3)+(temp<<1)+9;
		ans=temp/(long long)m-ans;
		if(n==1) ans++;
		printf("%I64d\n",ans);
	}
	return 0;
}
