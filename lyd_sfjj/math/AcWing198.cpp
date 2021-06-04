#include <cstdio>

using namespace std;
typedef long long LL;
const LL stand[] = {2,3,5,7,11,13,17,19,23,29};
LL N;
LL ans = 1;
LL num = 1;

void dfs(LL now,int id,int lim,LL count)
{
	if (now > N) return;
	if (count > num || (count == num && now < ans))
	{
		num = count;
		ans = now;
	}
	for (int i = 1; i <= lim && now < N; ++i)
	{
		now *= stand[id];
		dfs(now,id+1,i,count*(i+1));
	}
}

int main()
{
	scanf("%lld",&N);
	dfs(1ll,0,32,1);
	printf("%lld\n",ans);
	return 0;
}