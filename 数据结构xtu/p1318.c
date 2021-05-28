#include <stdio.h>

int s[10003];

int main()
{
	int i,n,data,count = 0;
	scanf("%d %d", &n,&data);
	for (i = 1; i <= n; ++i)
		scanf("%d", &s[i]);
	int l = 1, r = n, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		++count;
		if (s[mid] == data)
			break;
		else if(s[mid] < data)
			l = mid + 1;
		else r = mid - 1;
	}
	if (s[mid] == data) printf("%d\n",count);
	else printf("0\n");
	return 0;
}