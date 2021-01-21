#include <cstdio>
using namespace std;

int main()
{
	int time,a,b,c,d,e;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		printf("%d\n",a+b+c+e+d);
	}
	return 0;
}
