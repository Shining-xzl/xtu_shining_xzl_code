#include <cstdio>

using namespace std;

typedef unsigned int Ut;
const Ut mod = 1e9+7;
const Ut lim = 2e4+3;

Ut fun[lim][10];

void get_pre()
{
	fun[0][0] = 1;
	for (Ut i = 1; i < lim; ++i)
	{
		for (Ut j = 0; j < 10; ++j)
		{
			if(j == 0) fun[i][j] = fun[i-1][9] + fun[i-1][0];
			else if(j == 1) fun[i][j] = fun[i-1][9] + fun[i-1][0] + fun[i-1][1];
			else fun[i][j] = fun[i-1][j] + fun[i-1][j-1];
			fun[i][j] %= mod;
		}
	}
}

Ut solve(Ut m)
{
	Ut ans = 0;
	Ut mx = m/10;
	for (int i = 0; i < 10; ++i)
	{
		ans += fun[mx][i];
		if(ans >= mod)
			ans -= mod;
	}
	m = m%10;
	if(ans >= mod) ans -= mod;
	for (Ut i = 0; i < m; ++i)
	{
		ans += fun[mx][9-i];
		if(ans >= mod) ans -= mod;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	Ut ans,m,x;
	get_pre();
	while(T--)
	{
		ans = 0;
		scanf("%u %u", &x,&m);
		while(x>0)
		{
			ans = ans + solve(m+x%10);
			if(ans >= mod) ans -= mod;
			x /= 10;
		}
		printf("%u\n", ans);
	}
	return 0;
}