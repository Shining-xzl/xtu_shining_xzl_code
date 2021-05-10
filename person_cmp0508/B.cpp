#include <cstdio>

using namespace std;

char s[103];

int main()
{
	int ans;
	while(scanf("%s", s) == 1)
	{
		ans = -1;
		for (int i = 1; s[i] != 0; ++i)
		{
			if(s[i] != s[i-1])
			{
				ans = 2;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}