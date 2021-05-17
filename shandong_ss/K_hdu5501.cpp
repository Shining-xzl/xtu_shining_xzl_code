#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int lim = 1003;

struct point
{
	int start;
	int b,c;
	operator < (const point & x) const
	{
		return c * x.b < b * x.c;
	}
}s[lim];
int n,m;
long long dp[lim*3];

void init()
{
	scanf("%d%d", &n,&m);
	for (int i = 0; i < n; ++i)
		scanf("%d %d %d", &s[i].start,&s[i].b,&s[i].c);
	sort(s,s+n);
	memset(dp,0,sizeof(dp));
}

#define Max(x,y) ((x)>(y)?(x):(y))

void solve()
{
	for (int i = 0; i < n; ++i)
		for (int j = m; j - s[i].c >= 0; --j)
			dp[j] = Max(dp[j],dp[j-s[i].c] + (long long)s[i].start - (long long)j * (long long)s[i].b);
	long long ans = 0;
	for (int i = 0; i <= m; ++i)
		ans = Max(ans,dp[i]);
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		solve();
	}
	return 0;
}