#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int lim = 1e4+1;
int p,q,r,s;
bool not_prime[lim+3];
int prime[1300],len = 0;
int num[1300];

void prime_get()
{
	for (int i = 2; i < lim; ++i)
	{
		if(!not_prime[i])
			prime[len++] = i;
		for (int j = 0; j < len && prime[j]*i < lim; ++j)
		{
			not_prime[i*prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	}
}

void fill_num(int x,int offset)
{
	int temp,count;
	for (int i = 0; i < len; ++i)
	{
		temp = x;
		if(temp < prime[i]) break;
		count = 0;
		while(temp >= prime[i])
		{
			count += temp/prime[i];
			temp /= prime[i];
		}
		num[i] += count * offset;
	}
}

double get_ans()
{
	double ans = 1.0;
	for (int i = 0; i < len; ++i)
		ans *= pow(prime[i],num[i]);
	return ans;
}

int main()
{
	prime_get();
	while(scanf("%d %d %d %d", &p,&q,&r,&s) == 4)
	{
		memset(num, 0, sizeof(num));
		fill_num(p,1);
		fill_num(q,-1);
		fill_num(p-q,-1);
		fill_num(r,-1);
		fill_num(s,1);
		fill_num(r-s,1);
		printf("%.5f\n", get_ans());
	}
	return 0;
} 
