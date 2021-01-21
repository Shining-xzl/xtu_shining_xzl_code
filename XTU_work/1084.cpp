#include <stdio.h>
#include <math.h>
using namespace std;
const double pi=3.14159265;
int main()
{
	double a,b,A,ans;
	scanf("%lf%lf%lf",&a,&b,&A);
	ans=sqrt(a*a+b*b-2*a*b*cos(pi*A/180.0));
	printf("%g\n",ans);
	return 0;
}
