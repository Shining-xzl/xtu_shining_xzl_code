#include <cstdio>

using namespace std;

const int lim = 1130;
bool not_prime[lim];
int prime[200],len = 0;
int ans[1123][16];

void get_prime()
{
	for (int i = 2; i < lim; ++i)
	{
		if (!not_prime[i]) prime[len++] = i;
		for (int j = 0; j < len && prime[j] * i < lim; ++j)
		{
			not_prime[prime[j] * i] = 1;
			if(!(i%prime[j])) break;
		}
	}
}

void get_ans()
{
	ans[0][0] = 1;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 1120; j - prime[i] >= 0; --j)
		{
			for (int k = 14; k > 0; k--)
			{
				ans[j][k] += ans[j-prime[i]][k-1];
			}
		}
	}
}

int main()
{
	get_prime();
	get_ans();
	int n,k;
	while(scanf("%d %d", &n,&k) == 2)
	{
		if(n == k && n == 0) break;
		printf("%d\n", ans[n][k]);
	}
	return 0;
} 
