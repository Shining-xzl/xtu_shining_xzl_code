#include <cstdio>
using namespace std;

const int lim = 5e4+3;

int phi[lim],prime[lim],len = 0;
bool Not_prime[lim];

void get_prime_phi()//线型欧拉筛——素数&欧拉函数
{
	phi[1] = 1;
	for (int i = 2; i < lim; ++i)
	{
		if(!Not_prime[i])
		{
			phi[i] = i - 1;
			prime[len++] = i;
		}
		for (int j = 0; j < len && prime[j] * i < lim; ++j)
		{
			Not_prime[prime[j]*i] = 1;
			if(i%prime[j] == 0)
			{
				phi[i*prime[j]] = phi[i] * prime[j]; 
				break;
			}
			else phi[prime[j]*i] = phi[i] * (prime[j] - 1);
		}
	}
	for (int i = 2; i < lim; ++i)
		phi[i] += phi[i-1];
}

int main()
{
	get_prime_phi();
	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		if(n == 1) printf("1\n");
		else printf("%d\n", 2*phi[n] - 1);
	}
	return 0;
} 
