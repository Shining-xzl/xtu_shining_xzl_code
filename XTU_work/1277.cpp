#include <cstdio>
using namespace std;

int main()
{
	char s[3];
	int n,i,j;
	while(scanf("%s",s)==1)
	{
		n=s[0]-64;
		for(i=1;i<=n;i++)
		{
			for(j=(n<<1);j>i;j--)
				printf(" "); 
			for(j=1;j<=i;j++)
				printf("%c",64+j);
			for(j=i-1;j>0;j--)
				printf("%c",64+j);
			printf("\n");
		}
		for(i=1;i<=n;i++)
		{
			for(j=n;j>i;j--)
				printf(" ");
			for(j=1;j<=i;j++)
				printf("%c",64+j);
			for(j=i-1;j>0;j--)
				printf("%c",64+j);
			for(j=n*2-i*2+1;j>0;j--)
				printf(" ");
			for(j=1;j<=i;j++)
				printf("%c",64+j);
			for(j=i-1;j>0;j--)
				printf("%c",64+j);
			printf("\n");
		}
	}
	return 0;
}
