#include <cstdio>
using namespace std;
const int k = 11 * 111 - 11 - 111;
int dp[1500];

int main()
{
	int T,n;
	dp[0] = 1;
	for (int i = 0; i <= 1200; ++i)
		if (dp[i]) dp[i+11] = dp[i+111] = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if (n > 1200 || dp[n] == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}