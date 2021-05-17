#include <cstdio>
using namespace std;
typedef long long LL;

const LL MOD = 1e9+7;

LL f[1003];

LL get(int x)
{
	LL res = 0;
	for (int i = 1; i < x; ++i)
	{
		if((x-1) % i == 0)
		{
			res += f[i];
			if(res >= MOD) res -= MOD;
		}
	}
	return res;
}

int main()
{
	f[1] = 1;
	for (int i = 2; i <= 1000; ++i)
		f[i] = get(i);
	int Case = 0,n;
	while(scanf("%d",&n) == 1)
	{
		printf("Case %d: %lld\n", ++Case,f[n]);
	}
	return 0;
} 
