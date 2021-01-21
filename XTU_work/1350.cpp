#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int time;
	double x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%lf",&x);
		x=sqrt(1-x*x);
		printf("%.3lf\n",x);
	}
}
