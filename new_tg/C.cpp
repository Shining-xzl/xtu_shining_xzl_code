#include <cstdio>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
const int lim = 1e6+4;
LL f[lim],inv[lim];

LL fast_pow(LL x,LL p)
{
	LL res = 1;
	while(p > 0LL)
	{
		if(p&1LL) res = res * x % mod;
		x = x * x % mod;
		p >>= 1LL;
	}
	return res;
}

void init()
{
	f[0] = inv[0] = 1LL;
	f[1] = inv[1] = 1LL;
	for (int i = 2; i < lim; ++i)
	{
		f[i] = f[i-1] * i % mod;
		inv[i] = fast_pow(f[i],mod-2);
	}
}

LL get_C(int n,int m)
{
	return f[n] * inv[m] % mod * inv[n-m] % mod;
}

int main()
{
	init();
	LL n,k,ans = 0,p,los;
	scanf("%lld %lld", &n,&k);
	p = n/k;
	for (LL i = 1; i <= p; ++i)
	{
		los = n - i * k;
		ans = (ans + get_C(los+i-1,i-1)) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}