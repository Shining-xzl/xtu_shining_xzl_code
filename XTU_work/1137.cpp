#include <cstdio>
using namespace std;

int main()
{
	int time,n,i,j;
	char s[3];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		n=s[0]-64;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) 
				printf(" ");
			printf("%c\n",64+i);
			for(j=1;j<=n-i;j++)
				printf(" ");
			for(j=0;j<(i<<1);j++)
				printf("%c",64+i);
			printf("%c\n",64+i);	
		}
	}
	return 0;
}
