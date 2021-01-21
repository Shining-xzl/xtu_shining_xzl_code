#include <cstdio>
using namespace std;

int main()
{
	int n,con=0,i,j;
	char s[3];
	while(scanf("%s",&s)==1)
	{
		if(s[0]=='#') return 0;
		n=s[0]-64;
		printf("case %d:\n",++con);
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++) printf(" ");
			for(j=0;j<n-i;j++) printf("%c",65+j);
			for(j=n-i-2;j>=0;j--) printf("%c",65+j);
			printf("\n");
		}
	}
	return 0;
}
