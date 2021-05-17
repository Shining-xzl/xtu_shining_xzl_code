#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;
const int lim = 1e5+3;
const LL MOD = 1e9+7;
LL f[lim],fc[lim];

LL fast_pow(LL a,LL p,LL mod)
{
	LL res = 1;
	while(p > 0)
	{
		if(p & 1LL) res = res * a % MOD;
		p >>= 1LL;
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
		fc[i] = fast_pow(f[i],MOD-2,MOD);
	}
}

LL get_C(int n,int m)
{
	return f[n] * fc[m] % MOD * fc[n-m] % MOD;
}

#define Abs(x) ((x)>0?(x):-(x))

int main()
{
	prime();
	int n,T,w;
	LL ans;
	int x,c;
	int dis;
	while(scanf("%d %d %d", &n,&T,&w) == 3)
	{
		ans = 0LL;
		while(n--)
		{
			scanf("%d %d", &x,&c);
			dis = Abs(x-w);
			if(dis > T) continue;
			if((T&1) == (dis&1))
			{
				ans += c * get_C(T,T/2-dis/2);
				ans %= MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}