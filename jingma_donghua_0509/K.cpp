#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 1e5+3;
int coer[lim][12];
int dp[lim][12];
int N;

#define Max(x,y) (x>y?x:y)

int main()
{
	int k,p,t,T;
	while(scanf("%d",&N) == 1)
	{
		memset(coer, 0, sizeof(coer));
		memset(dp, -0x3f,sizeof(dp));
		T = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d %d", &t,&p,&k);
			T = Max(T,t);
			if(k) --coer[t][p];
			else ++coer[t][p];
		}
		dp[0][5] = 0;
		for (int i = 1; i <= T; ++i)
			for (int j = 0; j <= 10; ++j)
			{
				dp[i][j] = dp[i-1][j] + coer[i][j];
				if(j > 0) dp[i][j] = Max(dp[i][j], dp[i-1][j-1] + coer[i][j]);
				if(j < 10) dp[i][j] = Max(dp[i][j], dp[i-1][j+1] + coer[i][j]);
			}
		int ans = -0x3f3f3f3f;
		for (int i = 0; i <= 10; ++i)
			ans = Max(dp[T][i],ans);
		printf("%d\n", ans);
	}
	return 0;
}