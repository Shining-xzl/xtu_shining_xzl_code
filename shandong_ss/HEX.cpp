#include <cstdio>
using namespace std;

typedef long long LL;
const LL MOD = 1e9+7;
const int lim = 1e5+3;

LL f[lim],fc[lim];

LL fast_pow(LL a,LL p)
{
	LL res = 1;
	while(p > 0)
	{
		if(p & 1LL) res = res * a % MOD;
		p >>= 1;
		a = a * a % MOD;
	}
	return res;
}

void prime()
{
	f[0] = fc[0] = 1;
	f[1] = fc[1] = 1;
	for (int i = 2; i < lim; ++i)
	{
		f[i] = f[i-1] * i % MOD;
		fc[i] = fast_pow(f[i],MOD-2);
	}
}

LL get_C(int n,int m)
{
	return f[n] * fc[m] % MOD * fc[n-m] % MOD;
}
#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	int n,m;
	int l,r,p;
	LL ans;
	prime();
	while(scanf("%d %d", &n,&m) == 2)
	{
		// printf("%lld\n",get_C(n,m));
		--n;
		l = m - 1;
		r = n - l;
		p = Min(l,r);
		ans = 0LL;
		for (int i = 0; i <= p; ++i)
		{
			ans = (ans + get_C(n-i,i) * get_C(n-i-i,l-i) % MOD) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}