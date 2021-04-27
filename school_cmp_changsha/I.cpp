#include <cstdio>

using namespace std;
const long long MOD = 998244353;

long long a[2003][2003];
long long c[2003][2003];
int n,m;

void get_C()
{
	c[0][0] = 1;
	for(int i = 1; i <= 2000; ++i)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			c[i][j] %= MOD;
		}
	}
}

void get_A()
{
	a[0][0] = 1;
	for (long long i = 1; i <= 2000; ++i)
	{
		a[i][0] = 1;
		for (long long j = 1; j <= i; ++j)
		{
			a[i][j] = a[i][j-1] * (i-j+1) % MOD;
		}
	} 
}

int main()
{
	
	get_C();
	get_A();
	scanf("%d %d",&n,&m);
	int t;
	if(n < m)
	{
		t = n;
		n = m;
		m = t;	
	}
	long long ans = 0, temp;
	for (int i = 0; i <= m; ++i)
	{
		temp = (c[n][i] * a[m][i]) % MOD;
		ans = (ans + temp) % MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
