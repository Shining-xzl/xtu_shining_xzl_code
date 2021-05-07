#include <cstdio>

using namespace std;

int ans[13][13];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		for (int i = 1; i <= 9; i += 2)
			for (int j = 1; j <= i; j += 2)
				scanf("%d", &ans[i][j]);
		for (int i = 3; i <= 9; i += 2)
			for (int j = 2; j <= i; j += 2)
				ans[i][j] = ans[i-2][j-1] - ans[i][j-1] - ans[i][j+1] >> 1;
		for (int i = 2; i < 9; i += 2)
			for (int j = 1; j <= i; ++j)
				ans[i][j] = ans[i+1][j] + ans[i+1][j+1];
		for (int i = 1; i <= 9; ++i)
		{
			printf("%d", ans[i][1]);
			for (int j = 2; j <= i; ++j)
				printf(" %d",ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
} 
