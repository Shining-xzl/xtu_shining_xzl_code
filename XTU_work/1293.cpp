#include <cstdio>
using namespace std;

int main()
{
	int time,n,i,j;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=n-1;i>=0;i--)
		{
			for(j=0;j<i;j++)
				printf(" ");
			for(j=n;j>i;j--)
				printf("%c",64+j);
			for(j=i+2;j<=n;j++)
				printf("%c",64+j);
			printf("\n");
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
				printf(" ");
			for(j=n;j>i;j--)
				printf("%c",64+j);
			for(j=i+2;j<=n;j++)
				printf("%c",64+j);
			printf("\n");
		}
	}
	return 0;
}
