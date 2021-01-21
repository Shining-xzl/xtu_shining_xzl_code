#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	printf("%g\n",sqrt((a-c)*(a-c)+(b-d)*(b-d)));
	return 0;
}
