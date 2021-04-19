#include <stdio.h>

int main()
{
	int n,i;
	double x,t;
	scanf("%lf %d",&x,&n);
	t = x;
	for (i = 0; i < n; ++i)
		x = t / ( i + 1.0 + x);
	printf("%.2lf\n", x);
	return 0;
}