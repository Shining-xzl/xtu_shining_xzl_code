#include <cstdio>
using namespace std;
const int lim = 1e3+3;
const int MOD = 10056;

int C[lim][lim];
int ans[lim];

void get_C()
{
	C[0][0] = 1;
	for (int i = 1; i <= 1000; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			if(C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}
	ans[0] = 1;
	ans[1] = 1;
	for (int i = 2; i <= 1000; ++i)
		for (int j = 1; j <= i; ++j)
			ans[i] = (ans[i] + C[i][j] * ans[i-j] % MOD) % MOD;
}

int main()
{
	int T,n;
	get_C();
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &n);
		printf("Case %d: %d\n", i+1,ans[n]);
	}
	return 0;
} 
