#include <cstdio>
using namespace std;

int main()
{
	int time,n,i,j;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
			printf("-");
		printf("\n");
		for(i=1;i<(n>>1);i++)
		{
			for(j=1;j<i;j++)
				printf(" ");
			printf("\\");
			if(i==1)
			{
				for(j=n-1-(i<<1);j>0;j--)
					printf(" ");
			}
			else
			{
				for(j=n-1-(i<<1);j>0;j--)
					printf("*");
			}
			printf("/\n");
		}
		for(i=(n>>1)-1;i>0;i--)
		{
			for(j=1;j<i;j++)
				printf(" ");
			printf("/");
			for(j=(n>>1)-i-1;j>0;j--)
				printf(" ");
			printf("*");
			for(j=(n>>1)-i-1;j>0;j--)
				printf(" ");
			printf("\\\n");
		}
		for(i=1;i<n;i++)
			printf("-");
		printf("\n\n");
	}
	return 0;
}
