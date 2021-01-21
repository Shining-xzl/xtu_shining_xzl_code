#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double x;
	scanf("%lf",&x);
	if(x<0) x=0;
	else if(x>=0&&x<=1) x*=x;
	else x=sqrt(x);
	printf("%g\n",x);
	return 0;
}