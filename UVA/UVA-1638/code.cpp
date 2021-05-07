#include <cstdio>
using namespace std;
typedef long long LL;

LL ans[23][23][23];

int main()
{
	ans[1][1][1] = 1;
	for (int i = 2; i <= 20; ++i)
	{
		for (int l = 1; l <= i; ++l)
		{
			for (int r = 1; r <= (i-l+1); ++r)
			{
				ans[i][l][r] = ans[i-1][l-1][r] + ans[i-1][l][r-1] + (i-2)*ans[i-1][l][r];
			}
		}
	}
	int T,n,l,r;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &n, &l,&r);
		printf("%lld\n",ans[n][l][r] );
	}
	return 0;
} 
