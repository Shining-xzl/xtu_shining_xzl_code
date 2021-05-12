#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long LL;

LL N,A,B,C;

unordered_map <LL,LL> ans;

#define Min(x,y) ((x)<(y)?(x):(y))

LL dfs(LL now)
{
	if(ans.find(now) != ans.end()) return ans[now];
	else
	{
		if(now & 1LL) ans[now] = Min(dfs(now+1) + C,dfs(now-1) + A);
		else ans[now] = Min(now * A,dfs(now>>1)+B);
		return ans[now];
	}
}

int main()
{
	while(scanf("%lld %lld %lld %lld", &N,&A,&B,&C) == 4)
	{
		ans.clear();
		ans[0] = 0;
		ans[1] = A;
		printf("%lld\n", dfs(N));
	}
	return 0;
}