#include <stdio.h>

const int F=-0x3f3f3f3f;
int s[1003];
int n,m;

int main()
{
	scanf("%d %d", &n, &m);
	int i;
	for(i = 0; i < n; ++i)
		scanf("%d", &s[i]);
	while(m--)
	{
		scanf("%d", &i);
		s[i] = F;
	}
	for(i = 0; i < n; ++i)
		if(s[i] != F)
		printf("%d ", s[i]);
	return 0;
}