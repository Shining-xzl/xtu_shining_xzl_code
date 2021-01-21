#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int time;
	int a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		printf("%.1lf\n",(double)(a*b)/2.0);
	}
	return 0;
}
