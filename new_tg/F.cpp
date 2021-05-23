#include <cstdio>

using namespace std;
typedef long long LL;
const int lim = 1e6+3;
int n,m;
int val[lim],color[lim];
LL p[lim][2];
LL dp[2][lim][2];

#define Max(x,y) ((x)>(y)?(x):(y))

void process()
{
	int l,r;
	for (int i = 0; i < n; ++i)
	{
		p[i][0] = p[i][1] = -1e13;
		l = i * m;
		r = l + m;
		for (int j = l; j < r; ++j)
		{
			if(color[j] == 1) p[i][1] = Max(p[i][1],val[j]);
			else p[i][0] = Max(p[i][0],val[j]);
		}
	}
}

int main()
{
	int T,all;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d", &n,&m);
		all = n*m;
		for (int i = 0; i < all; ++i)
			scanf("%d",&val[i]);
		for (int i = 0; i < all; ++i)
			scanf("%d",&color[i]);
		process();
		dp[0][0][0] = p[0][0];
		dp[1][0][1] = p[0][1];
		dp[0][0][1] = -1e13;
		dp[1][0][0] = -1e13;
		for (int i = 1; i < n; ++i)
		{
			dp[0][i][1] = dp[0][i-1][0] + p[i][1];
			dp[1][i][1] = dp[1][i-1][0] + p[i][1];
			dp[1][i][0] = Max(dp[1][i-1][0],dp[1][i-1][1]) + p[i][0];
			dp[0][i][0] = Max(dp[0][i-1][0],dp[0][i-1][1]) + p[i][0];
		}
		LL ans;
		ans = Max(dp[1][n-1][0],dp[0][n-1][1]);
		ans = Max(ans,dp[0][n-1][0]);
		if(n == 1) 
			ans = Max(p[0][0],p[0][1]);
		if(ans < 0) ans = -1;
		printf("%lld\n", ans);
	}
	return 0;
}