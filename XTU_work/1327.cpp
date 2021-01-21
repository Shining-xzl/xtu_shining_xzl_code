#include <cstdio>
using namespace std;

int main()
{
	char c;
	int n,i,j;
	while(scanf("%c",&c)==1)
	{
		n=c-64;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",i>j?i+64:j+64);
			for(j=n-1;j>0;j--)
				printf("%c",i>j?i+64:j+64);
			printf("\n");
		}
		for(i=n-1;i>0;i--)
		{
			for(j=1;j<=n;j++)
				printf("%c",i>j?i+64:j+64);
			for(j=n-1;j>0;j--)
				printf("%c",i>j?i+64:j+64);
			printf("\n");
		}
	}
	return 0;
}
