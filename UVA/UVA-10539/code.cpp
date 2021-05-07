#include <cstdio>
using namespace std;

const int lim  = 1e6+3;

bool not_prime[lim];
int prime[lim],len;

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

int get_ans(long long x)
{
	int ans = 0;
	long long temp;
	for (int i = 0; i < len; ++i)
	{
		temp = (long long)prime[i] * prime[i];
		while(temp <= x)
		{
			++ans;
			temp *= (long long)prime[i];
		}
	}
	return ans;
}

int main()
{
	get_prime();
	int T;
	long long low,high;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld %lld", &low,&high);

		printf("%d\n",get_ans(high) - get_ans(low-1));
	}
	return 0;
} 
