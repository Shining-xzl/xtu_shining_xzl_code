#include <cstdio>
using namespace std;

int main()
{
	int now=0,a,b,time,max=0;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		now+=(b-a);
		if(max<now) max=now; 
	}
	printf("%d\n",max);
	return 0;
}
