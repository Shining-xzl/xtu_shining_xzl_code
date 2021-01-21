#include <cstdio>
using namespace std;

int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		for(i=1;i<n;i++) 
			printf(" ");
		printf("1\n");
		for(i=1;i<n;i++)
		{
			for(j=n-i-1;j>0;j--)
				printf(" ");
			for(j=1;j<=i;j++)
				printf("%d",j);
			printf("+");
			for(j=i;j>=1;j--)
				printf("%d",j);
			printf("\n");
		}
	}
	return 0;
}
