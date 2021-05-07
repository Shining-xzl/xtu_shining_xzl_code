/*
int 会溢出
有负数。。。。。。注意处理
*/
#include <cstdio>
using namespace std;
const int lim  = 1e5+3;

bool not_prime[lim];
int prime[100003],len;

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if(!not_prime[i]) prime[len++] = i;
		for (int j = 0; j < len && prime[j] * i < lim; ++j)
		{
			not_prime[prime[j] * i] = 1;
			if(!(i % prime[j])) break;
		}
	}
}

int gcd(int a,int b)
{
	if(b == 0) return a;
	else return gcd(b,a % b);
}

int main()
{
	get_prime();
	int i,ans,count;
	long long n;
	bool flag;
	while(scanf("%lld", &n) == 1 && n)
	{
		if(n < 0) flag = 1, n = -n;
		else flag = 0;
		i = 0;
		ans = 0;
		while(i < len && (long long)prime[i] * (long long)prime[i] <= n)
		{
			if(n % (long long)prime[i] == 0)
			{
				count = 0;
				while(n % (long long)prime[i] == 0)
				{
					++count;
					n /= (long long)prime[i];
				}
				ans = gcd(count,ans);
			}
			++i;
		}
		while(flag && ans%2 == 0 && ans > 0) ans /= 2;
		if(n > 1 || ans == 0) ans = 1;
		printf("%d\n", ans);
	}
	return 0;
} 
