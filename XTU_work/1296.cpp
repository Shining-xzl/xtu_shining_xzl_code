#include <cstdio>
using namespace std;

int main()
{
	int time,a,b,ansa,ansb;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		a--;
		ansa=a-a/3-a/2+a/6;
		ansb=b-b/3-b/2+b/6;
		printf("%d\n",ansb-ansa);
	}
	return 0;
}
