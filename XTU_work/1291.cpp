#include <cstdio>
#include <algorithm>
using namespace std;
int s[1003];
int sum[1003];
int n,m;

void solve()
{
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &s[i]);
	sort(s,s+n);
	sum[0] = s[0];
	for (int i = 1; i < n; ++i)
		sum[i] = sum[i-1] + s[i];
	int ans = sum[m-1], diff = s[m-1] - s[0];
	for (int i = m; i < n; ++i)
	{
		if (s[i] - s[i-m+1] < diff)
		{
			ans = sum[i] - sum[i - m];
			diff = s[i] - s[i-m+1];
		}
	}
	printf("%d %d\n", diff,ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
