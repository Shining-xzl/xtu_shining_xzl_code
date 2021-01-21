#include <stdio.h>
using namespace std;

char s[54][54];

void build(int a,int b,char c)
{
	int i;
	for(i=a;i<=b;i++)
	{
		s[a][i]=c;
		s[b][i]=c;
		s[i][a]=c;
		s[i][b]=c;
	}
}

int main()
{
	int time,n,i,j;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			build(i,n*2-i,65+n-i);
		n=n*2-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",s[i][j]);
			printf("\n");
		}
	}
	return 0;
}
