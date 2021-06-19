#include <cstdio>

using namespace std;
typedef long long ll;
const ll xlim = 9223372036854775807;
ll dp[70][70];
ll a[70];
int n;

#define Min(x,y) ((x)<(y)?(x):(y))

ll solve(int l,int r,int step)
{
	if (dp[l][r] < xlim) return dp[l][r];
	if (l == r)	return dp[l][r] = a[l] * (1ll << step);
	ll lval,rval;
	lval = solve(l+1,r,step+1) + a[l] * (1ll << step);
	rval = solve(l,r-1,step+1) + a[r] * (1ll << step);
	dp[l][r] = Min(lval,rval);
	return dp[l][r];
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld", &a[i]);
		for (int i = 0; i < 70; ++i)
			for (int j = i; j < 70; ++j)
				dp[i][j] = xlim;
		printf("%lld\n",solve(1,n,0));
	}
	return 0;
} 
