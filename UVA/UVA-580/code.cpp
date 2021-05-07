#include <cstdio>
using namespace std;

typedef long long LL;
LL ans[34];

void get_ans()
{
	ans[3] = 1;
	for (int i = 4; i < 31; ++i)
	{
		ans[i] = (1LL << (i-3));
		for (int j = 4; j <= i; ++j)
		{
			ans[i] += ((1LL << (j-4)) - ans[j-4]) * (1LL << (i-j));
		}
	}
}

int main()
{
	get_ans();
	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		printf("%lld\n", ans[n]);
	}
	return 0;
} 
