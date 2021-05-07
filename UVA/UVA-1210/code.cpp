#include <cstdio>
using namespace std;
const int lim = 10003;
bool not_prime[lim];
int prime[lim],len = 0;
int num[lim];

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if (!not_prime[i]) prime[++len] = i;
		for (int j = 1; j <= len && prime[j] * i < lim; ++j)
		{
			not_prime[prime[j] * i] = 1;
			if(!(i%prime[j])) break;
		}
	}
	for (int i = 1; i <= len; ++i)
		prime[i] += prime[i-1];
	for (int i = 1; i <= len; ++i)
		for (int j = 0; j < i; ++j)
			if(prime[i] - prime[j] < lim)
			++num[prime[i] - prime[j]];

	
}
int main()
{
	get_prime();
	int n;
	while(scanf("%d",&n) == 1 && n)
		printf("%d\n", num[n]);
	return 0;
} 
