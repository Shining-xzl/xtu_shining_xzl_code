#include <stdio.h>

#define lim 1003
int val[lim],pos[lim];

int main()
{
	int i,head,len;
	scanf("%d %d", &len,&head);
	for (i = 1; i <= len; ++i)
		scanf("%d %d", &val[i],&pos[i]);
	while(head != 0)
	{
		printf("%d", val[head]);
		head = pos[head];
		if(head != 0) printf(" ");
	}
	return 0;
}