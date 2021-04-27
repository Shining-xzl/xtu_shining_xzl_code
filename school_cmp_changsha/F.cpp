#include <cstdio>
using namespace std;
const int lim = 1e5+3;
#define Max(x,y) ((x)>(y)?(x):(y))

int n,s[lim],dp[lim];
int k[lim];

int main()
{
	scanf("%d",&n);
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&s[i]);
		dp[i] = 1;
		for (int j = i-1; j >= 0; --j)//dp优化新姿势，简单加上max数组，表示当前最大。。。。。方便跳出，然而有时候的确没什么大用处
		{
			if(s[i] % s[j] != 0)
			{
				dp[i] = Max(dp[i],dp[j]+1);
				if(dp[j] == k[j])
					break;
			}
		}
		if(max < dp[i])
			max = dp[i];
		k[i] = max;
	}
	printf("%d\n", k[n-1]);
	return 0;
}