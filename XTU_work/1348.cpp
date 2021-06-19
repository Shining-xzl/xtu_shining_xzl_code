#include <cstdio>
using namespace std;
int remainder[13];
int n,k,ans;

void initail()
{
	for (int i = 0; i < 13; ++i)
		remainder[i] = 0;
	for (int i = 9; i > 0; --i)
		remainder[i * k % 10] = i;
}

void del_0()
{
	if (n % 10 == 0) ++ans;
	while(n % 10 == 0)	n /= 10;
}

void get_ans()
{
	ans = 0;
	while(n >= k)
	{
		if (n % 10 == 0) del_0();
		else if (remainder[n%10] == 0 || remainder[n%10] > n / k)
			ans += n / k, n %= k;
		else
		{
			ans += remainder[n%10];
			n -= remainder[n%10] * k;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d", &n,&k);
		initail();
		get_ans();
		printf("%d %d\n",ans,n);
	}
	return 0;
}