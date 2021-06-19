#include <cstdio>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll f3 = 333333336;

int main()
{
	int n;
	ll ans;
	ll p;
	while(scanf("%d", &n) == 1)
	{
		if (n == 0) break;
		p = (n + 1) / 2;
		ans = 4 * p % mod * (p + 1) % mod * (2*p + 1) % mod * f3 % mod;
		ans -= 8 * p % mod * (p + 1) % mod;
		ans += 9 * p % mod;
		if ((n & 1) == 0)
		{
			p = n / 2 + 1;
			ans += 4 * p % mod * p % mod - 8 * p % mod + 4;
		}
		ans %= mod;
		ans = (ans + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}