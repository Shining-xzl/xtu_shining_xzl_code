#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 2e5+5;

bool not_prime[lim];
int prime[lim],len = 0;
int n,m;
int a[lim],b[lim];

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if (!not_prime[i])
			prime[len++] = i;
		for (int j = 0; j < len && i * prime[j] < lim; ++j)
		{
			not_prime[i * prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
}

int main()
{
	int x,l,r;
	int Max = 0, Min = 1e9;
	get_prime();
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &x);
		if(x < Min) Min = x;
		if(x > Max) Max = x;
		++b[x];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		l = lower_bound(prime,prime+len,a[i]+Min) - prime;
		r = upper_bound(prime,prime+len,a[i]+Max) - prime;
		for (int j = l; j < r; ++j)
			ans += b[prime[j]-a[i]];
	}
	printf("%lld\n", ans);
	return 0;
}
