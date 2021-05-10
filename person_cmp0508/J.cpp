#include <cstdio>

using namespace std;
const int lim = 1e6+4;
const int MOD = 998244353;

int flat[lim],sharp[lim];

int main()
{
	int n;
	scanf("%d", &n);
	flat[0] = 1;
	for (int i = 2; i <= n; ++i)
	{
		flat[i] = 2 * sharp[i-1] % MOD;
		sharp[i] = (flat[i-2] + sharp[i-2]) % MOD;
	}
	printf("%d\n", sharp[n]);
	return 0;
}