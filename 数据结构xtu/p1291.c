#include <stdio.h>

int main()
{
	int x,n,pre = -1e9;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d", &x);
		if(x != pre)
			printf("%d ", x);
		pre=x;
	}
	return 0;
}