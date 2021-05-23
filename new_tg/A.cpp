#include <cstdio>

using namespace std;
const int lim = 1e4+3;
int num[lim];
int ans = 0;

void dfs(int now)
{
	++ans;
	if(num[now] <= 1) return;
	dfs(now<<1);
	dfs(now<<1|1);
}

int main()
{
	int n,k,x;
	scanf("%d %d",&n,&k);
	while(k--)
	{
		scanf("%d",&x);
		x += n-1;
		while(x)
		{
			++num[x];
			x /= 2;
		}
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}