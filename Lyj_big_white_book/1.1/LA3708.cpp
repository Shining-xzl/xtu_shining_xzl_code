#include <cstdio>
#include <cmath>
using namespace std;
int n,m;

#define abs(x) ((x)>0?(x):-(x))

int main()
{
	double ans,a,b,now,k;
	while(scanf("%d%d",&n,&m) == 2)
	{
		ans = 0;
		a = 10000.0 / n;
		b = 10000.0 / (n+m);
		now = 0.0;
		for (int i = 1; i < n; ++i)
		{
			now += a;
			k = floor(now/b + 0.5) * b;
			ans += abs(now-k);
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}