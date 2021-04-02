#include <stdio.h>
int val[1003],pre[1003];

int main()
{
	int n,i,x;
	scanf("%d %d",&n,&x);
	pre[x] = -1;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d %d",&val[i], &x);
		pre[x] = i;
	}
	i = pre[0];
	while(i != -1)
	{
		printf("%d ", val[i]);
		i = pre[i];
	}
	return 0;
}