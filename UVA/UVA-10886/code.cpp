#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;
ULL seed;

long double gen()
{
	long double Z = (long double) 1.0 /  (1LL << 32);
	seed >>= 16;
	seed &= (1ULL << 32) - 1;
	seed *= seed;
	return seed * Z;
}

int main()
{
	int T,n;
	long double x2,temp,sumx;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d %llu", &n,&seed);
		x2 = 0;
		sumx = 0;
		for (int j = 1; j <= n; ++j)
		{
			temp = gen();
			x2 += temp * temp;
			sumx += temp;
		}
		printf("Case #%d: %.5Lf\n", i+1,sqrt(x2/n - sumx/n * sumx/n));
	}
	return 0;
} 
