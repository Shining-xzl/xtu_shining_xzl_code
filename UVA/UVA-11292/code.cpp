#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 20003;
int a[lim],b[lim];

int main()
{
	int n,m;
	int ans,op;
	while(scanf("%d %d", &n,&m) == 2)
	{
		if(n == m && n == 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		ans = 0;
		op = 0;
		sort(a,a+n); sort(b,b+m);
		for (int i = 0; i < m; ++i)
		{
			if(op >= n) break;
			if(a[op] <= b[i]) ans += b[i],++op;
		}
		if(op < n) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}
	return 0;
} 
