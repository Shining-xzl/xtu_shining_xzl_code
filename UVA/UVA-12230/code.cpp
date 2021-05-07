#include <cstdio>
using namespace std;
int n,D;
double ans,p,l,v;
int main()
{
	int Case = 0;
	while(scanf("%d %d", &n, &D) == 2)
	{
		if(n == D && n == 0) break;
		ans = (double)D;
		while(n--)
		{
			scanf("%lf %lf %lf", &p,&l,&v);
			ans -= l;
			ans += (2*l/v);
		}
		printf("Case %d: %.3f\n\n",++Case, ans);
	}
	return 0;
} 
