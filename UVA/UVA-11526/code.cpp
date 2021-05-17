#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

LL solve(LL n)
{
	LL res = 0LL;
	LL k = sqrt(n);
	for (int i = 1; i <= k; ++i)
		res += n / i;
	return res * 2 - k * k;
}

int main()
{
	int T;
	LL n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n", solve(n));
	}
	return 0;
} 
