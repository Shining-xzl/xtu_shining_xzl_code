#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double a,b,c,ans,si;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a+b>c&&b+c>a&&a+c>b)
	{
		si=(a*a+b*b-c*c)/(2.0*a*b);
		si=sqrt(1-si*si);
		ans=a*b*si/2.0;
		printf("%.2lf",ans);
	}
	else printf("Not a triangle.");
	return 0;
}
