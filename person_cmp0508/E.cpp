#include <cstdio>
#include <cmath>

using namespace std;

const int lim = 1e6+4;
#define Max(x,y) ((x)>(y)?(x):(y))
#define debug(x) printf("%s : %.3f\n", #x,x );
double f[lim];
int n;
int a[lim];


int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	double temp,ax,a1,a2;
	f[n-1] = a[n-1];
	for (int i = n-2; i >= 0; --i)
	{
		ax = a[i];
		temp = ax - f[i+1];
		if (f[i+1] >= ax)  temp = Max(f[i+1] - ax,temp);
		else 
		{
			a1 = floor(ax - sqrt(ax * f[i+1]));
			a2 = ceil(ax - sqrt(ax * f[i+1]));
			// debug(a1);
			// debug(a2);
			if (a1 < ax / 2)
			{
				a1 = a1*2 - ax + f[i+1] - 2*a1*f[i+1]/(ax-a1);
				temp = Max(a1,temp);
			}
			if (a2 < ax / 2)
			{
				a2 = a2*2 - ax + f[i+1] - 2*a2*f[i+1]/(ax-a2);
				temp = Max(a2,temp);
			}
		}
		f[i] = temp;
	}
	printf("%.5f\n", f[0]);
	return 0;
}