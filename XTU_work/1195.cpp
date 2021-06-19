#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 1e4+3;
struct way
{
	int a,b,w;
	bool operator < (const way &x) const
	{
		return w > x.w;
	}
}s[lim];
int fa[1003],n,m;

int get_fa(int x)
{
	if (fa[x] == x) return x;
	else return fa[x] = get_fa(fa[x]);
}

int main()
{
	int T,a,b;
	int sum;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n,&m);
		for (int i = 0; i < m; ++i)
			scanf("%d %d %d", &s[i].a,&s[i].b,&s[i].w);
		sort(s,s+m);
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
		sum = 0;
		for (int i = 0; i < m; ++i)
		{
			a = get_fa(s[i].a);
			b = get_fa(s[i].b);
			if (a != b)
			{
				sum += s[i].w;
				fa[a] = b;
				--n;
				if (n == 1) break;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}