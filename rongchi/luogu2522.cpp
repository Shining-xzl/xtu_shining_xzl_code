#include <cstdio>

using namespace std;
typedef long long LL;
const int lim = 5e4+4;

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
	int p,i = 1, Max = Min(a,b);
	while(i <= Max)
	{
		p = Min(Max, Min(a/(a/i),b/(b/i)));
		res += (LL)(sum[p] - sum[i-1]) * (LL)(a/i) * (LL)(b/i);
		i = p + 1;
	}
	return res;
}

int main()
{
	get_miu();
	int T,r1,l1,r2,l2,d;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d %d", &l1,&r1,&l2,&r2,&d);
		LL ans;
		ans = get_ans(r1/d,r2/d);
		ans += get_ans((l1-1)/d,(l2-1)/d);
		ans -= get_ans((l1-1)/d,r2/d);
		ans -= get_ans(r1/d,(l2-1)/d);
		printf("%lld\n",ans);
	}
	return 0;
}