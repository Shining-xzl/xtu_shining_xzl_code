/*
容斥与莫比乌斯
*/
#include <cstdio>

using namespace std;
typedef long long LL;
const int lim = 5e4+3;
int miu[lim],sum[lim];
bool vis[lim];

void get_miu()
{
	for (int i = 1; i < lim; ++i) miu[i] = 1;
	for (int i = 2; i < lim; ++i)
	{
		if (vis[i]) continue;
		miu[i] = -1;
		for (int j = i<<1; j < lim; j += i)
		{
			vis[j] = 1;
			if (j / i % i == 0) miu[j] = 0;
			else miu[j] *= -1;
		}
	}
	for (int i = 1; i < lim; ++i)
		sum[i] = sum[i-1] + miu[i];
}
#define Min(x,y) ((x)<(y)?(x):(y))
LL get_ans(int a,int b)
{
	LL res = 0;
	int i = 1,lim = Min(a,b),p;
	while(i <= lim)
	{
		p = Min(a/(a/i),b/(b/i));
		p = Min(lim,p);
		res += (LL)(sum[p] - sum[i-1]) * (a/i) * (b/i);
		i = p + 1;
	}
	return res;
}

int main()
{
	get_miu();
	int T,a,b,d;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &a,&b,&d);
		printf("%lld\n",get_ans(a/d,b/d));
	}
	return 0;
}