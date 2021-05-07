#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 1299730;
int prime[100005],len = 0;
bool not_prime[lim];

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if(!not_prime[i]) prime[len++] = i;
		for (int j = 0; j < len && prime[j] * i < lim; ++j)
		{
			not_prime[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		} 
	}
}

int main()
{
	get_prime();
	int n,op;
	while(scanf("%d", &n) == 1 && n)
	{
		op = lower_bound(prime,prime+len,n) - prime;
		if(prime[op] == n) printf("0\n");
		else printf("%d\n",prime[op] - prime[op-1]);
	}
	return 0;
} 
