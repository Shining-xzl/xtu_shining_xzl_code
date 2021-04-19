#include <cstdio>
using namespace std;
const int mod = 1e4+1;

int inv[mod+3];
int x[203];
int n;

void prime_inv()
{
	inv[1] = 1;
	for (int i = 2; i <= mod; ++i)
		inv[i] = (mod - mod/i) * inv[mod%i] % mod;
}

bool check(int a)
{
	int b;
	b = x[3] - (a*a%mod*x[1]) + mod;
	b %= mod;
	b = b * inv[a+1] % mod;
	for (int i = 2; i <= n*2; ++i)
	{
		if(i&1)
		{
			if(x[i] != (a * x[i-1] + b) % mod)
				return 0;
		}
		else x[i] = (a * x[i-1] + b) % mod;
	}
	return 1;
}

int main()
{
	prime_inv();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i*2+1]);
	for (int i = 0; i < mod; ++i)
		if(check(i))
			break;
	for (int i = 1; i <= n; ++i)
		printf("%d\n", x[i*2]);
	return 0;
} 
