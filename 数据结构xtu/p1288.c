#include <stdio.h>

int main()
{
	int n,m,i,ans = 0;
	scanf("%d %d",&n,&m);
	for (i = 2; i <= n; ++i)
		ans = (ans + m) % i;
	printf("%d\n", ans + 1);
	return 0;
}
