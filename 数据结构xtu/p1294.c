#include <stdio.h>

int main()
{
	int time;
	int stack[9],len,op,i,x;
	scanf("%d",&time);
	while(time--)
	{
		len = 0;
		op = 1;
		for (i = 1; i < 8; ++i)
		{
			scanf("%d",&x);
			while((len == 0 || stack[len] != x) &&  op < 8)
			{
				stack[++len] = op++;
			}
			if(len > 0 && stack[len] == x) --len;
		}
		if(len == 0) printf("Y");
		else printf("N");
	}
	return 0;
}