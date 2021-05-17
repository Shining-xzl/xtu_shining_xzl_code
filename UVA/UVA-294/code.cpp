#include <cstdio>
using namespace std;
const int lim = 1e5;
bool Not_prime[lim];
int prime[10000],len = 0;

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if (!Not_prime[i]) prime[len++] = i;
		for (int j = 0; j < len && i * prime[j] < lim; ++j)
		{
			Not_prime[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int get_num(int x)
{
	int i = 0;
	int res = 1,temp;
	while(prime[i] * prime[i] <= x)
	{
		if (x % prime[i] == 0)
		{
			temp = 1;
			while(x % prime[i] == 0)
			{
				++temp;
				x /= prime[i];
			}
			res *= temp;
		}
		++i;
	}
	if(x > 1) res <<= 1;
	return res;
}

int main()
{
	get_prime();
	int T,l,r;
	int num,res,temp;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &l,&r);
		res = 0;
		for (int i = l; i <= r; ++i)
		{
			temp = get_num(i);
			if(res < temp)
			{
				num = i;
				res = temp;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l,r,num,res);
	}
	return 0;
} 
