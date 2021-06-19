#include <cstdio>
using namespace std;
const int lim = 1003;

int s[lim];
int n,k;

bool check()
{
	for (int i = k+1; i <= n; ++i)
		if (s[i] != s[i-1]) return 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n,&k);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &s[i]);
		if (check())
		{
			int i = k - 1;
			for (; i > 0 && s[i] == s[i+1]; i--);
			printf ("%d\n",i);
		}
		else printf ("-1\n");
	}
	return 0;
}
