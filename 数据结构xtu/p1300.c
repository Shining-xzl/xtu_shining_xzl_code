#include <stdio.h>

int main()
{
	double a,b,c,d;
	double l,r,mid,lx,rx,temp;
	scanf("%lf %lf %lf %lf %lf %lf", &a,&b,&c,&d,&l,&r);
	lx = a * l * l * l + b * l * l + c * l + d;
	rx = a * r * r * r + b * r * r + c * r + d;
	while(r-l > 1e-7)
	{
		mid = (l + r) / 2;
		temp = a * mid * mid * mid + b * mid * mid + c * mid + d;
		if(temp * lx <= 0)
		{
			r = mid;
			rx = temp;
		}
		else
		{
			l = mid;
			lx = temp;
		}
			
	}
	printf("%.6f\n", r);
	return 0;
}