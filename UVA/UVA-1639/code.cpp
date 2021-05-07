/*
概率，组合数+对数公式
*/
#include <cstdio>
#include <cmath>
using namespace std;
const int lim = 4e5+3;
const long double E = 2.718281828459;
long double lnx[lim];

void prime_init()
{
	lnx[1] = 0;
	for (int i = 2; i < lim; ++i)
		lnx[i] = lnx[i-1] + log(i);
}

int n;
long double p;

int main()
{
	prime_init();
	int Case = 0;
	long double ans;
	long double exp;
	while(scanf("%d %Lf", &n,&p) == 2)
	{
		ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			exp = lnx[2*n-i] - lnx[n] - lnx[n-i] + (n+1) * log(p) + (n-i) * log(1-p);
			ans += i * pow(E,exp);
			exp = lnx[2*n-i] - lnx[n] - lnx[n-i] + (n+1) * log(1-p) + (n-i) * log(p);
			ans += i * pow(E,exp);
		}
		printf("Case %d: %.6Lf\n", ++Case,ans);
	}
	return 0;
} 
