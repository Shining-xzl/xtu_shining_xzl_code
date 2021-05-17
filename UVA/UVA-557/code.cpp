#include <cstdio>
#include <cmath>
using namespace std;
const int lim = 1e5+3;
const double E = 2.718281828459;
double lnx[lim];

int main()
{
	for (int i = 1; i < lim; ++i)
		lnx[i] = log(i*1.0) + lnx[i-1];
	int T,n;
	double ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n == 2) printf("0.0000\n");
		else
		{
			n -= 2;
			ans = lnx[n] - lnx[n/2] - lnx[n/2] - n * log(2);
			ans = pow(E,ans);
			ans = 1.0 - ans;
			printf("%.4f\n",ans);
		}
	}
	return 0;
} 
