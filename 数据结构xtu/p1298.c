#include <stdio.h>

int a[1003];
int n;

void _(int now)
{
	if(now > n) return;
	printf("%d ",a[now]);
	_(now<<1);
	_(now<<1|1);	
}

void __(int now)
{
	if(now > n) return;
	__(now<<1);
	printf("%d ",a[now]);
	__(now<<1|1);	
}

void ___(int now)
{
	if(now > n) return;
	___(now<<1);
	___(now<<1|1);
	printf("%d ",a[now]);
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	_(1);
	putchar('\n');
	__(1);
	putchar('\n');
	___(1);
	return 0;
}