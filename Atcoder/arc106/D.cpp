#include <cstdio>

using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int lim = 2e5+3;
int N,K;
LL inv[304];
LL stand[lim];
LL pow_k[lim];
LL sum[lim],sum_pow[lim];

void get_inv(int K)
{
	inv[1] = 1;
	for (int i = 2; i <= K; ++i)
	{
		inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD;
	}
}

int main()
{
	scanf("%d %d", &N,&K);
	get_inv(K);
	for (int i = 0; i < N; ++i)
	{
		pow_k[i] = 1;
		scanf("%lld", &stand[i]);	
	}
	sum[0] = N;
	LL temp = 1,ans,pow_2 = 1;
	for (int i = 1; i <= K; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			pow_k[j] = pow_k[j] * stand[j] % MOD;
			sum[i] = (sum[i] + pow_k[j]) % MOD;
		}
		temp = temp * inv[i] % MOD;
		pow_2 = pow_2 * 2 % MOD;
		sum_pow[i] = pow_2 * sum[i] % MOD;
		sum[i] = sum[i] * temp % MOD;
	}
	temp = 1;
	for (int i = 1; i <= K; ++i)
	{
		ans = 0;
		for (int j = 0; j <= i; ++j)
			ans = (ans + sum[j] * sum[i-j]) % MOD;
		temp = temp * i % MOD;
		ans = temp * ans % MOD;
		ans = (ans - sum_pow[i]) % MOD * inv[2] % MOD + MOD;
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}