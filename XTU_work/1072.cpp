#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int x;
	double xx;
	scanf("%d",&x);
	if(x>=0&&x<10)
	{
		xx=double(x)+3.0;
		xx=cos(xx);
		printf("%.5lf",xx);
	}
	else if(x>=10&&x<20)
	{
		xx=double(x)+7.5;
		xx=cos(xx);
		xx*=xx;
		printf("%.5lf",xx);
	}
	else if(x>=20&&x<30)
	{
		xx=double(x)+4.0;
		xx=cos(xx);
		xx=xx*xx*xx*xx;
		printf("%.5lf",xx);
	}
	else printf("Not define");
	return 0;
}
