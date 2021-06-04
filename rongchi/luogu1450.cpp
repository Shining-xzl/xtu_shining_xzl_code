/*
容斥的背包
*/
#include <cstdio>
using namespace std;
typedef long long LL;
const int lim = 1e5+3;
LL dp[lim],ans;
int c[5],n;
int num[5],S;

void dfs(int id,int dif,LL flag)
{
	if (dif > S) return;
	if (id > 3)
	{
		ans += flag * dp[S-dif]; // 合法与不合法情况
		return;
	}
	dfs(id+1,dif,flag);
	dfs(id+1,dif+c[id]*(num[id]+1),-flag);
}

int main ()
{
	scanf("%d %d %d %d %d", &c[0],&c[1],&c[2],&c[3],&n);
	dp[0] = 1ll;
	for (int i = 0; i < 4; ++i)
		for (int j = c[i]; j < lim; ++j)
			dp[j] += dp[j-c[i]]; // 无限制完全背包
	
	while(n--)
	{
		scanf("%d %d %d %d %d", &num[0],&num[1],&num[2],&num[3],&S);
		ans = 0;
		dfs(0,0,1ll);
		printf("%lld\n", ans);
	}
	return 0;
}