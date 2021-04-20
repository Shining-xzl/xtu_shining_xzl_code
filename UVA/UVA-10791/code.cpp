#include <cstdio>
using namespace std;
const int lim = 1e5+3;

bool not_prime[lim];
int prime[9600],len = 0;

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if(!not_prime[i])
			prime[len++] = i;
		for (int j = 0; j < len && prime[j]*i < lim; ++j)
		{
			not_prime[prime[j]*i] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
}

unsigned int solve(unsigned int x)
{
	unsigned int res = 0, i = 0, count = 0, temp;
	while(i < len && x > 1)
	{
		if(x%prime[i] == 0)
		{
			++count;
			temp = 1;
			while(x%prime[i] == 0)
			{
				temp *= prime[i];
				x /= prime[i];
			}
			res += temp;
		}
		++i;
	}
	if(x > 1)
	{
		++count;
		res += x;
	}
	if(count == 0) res+=2;
	else if(count == 1) ++res;
	return res;
}

int main()
{
	get_prime();
	unsigned int n,Case = 0;
	while(scanf("%u", &n) == 1 && n)
		printf("Case %d: %u\n", ++Case,solve(n));
	return 0;
} 
