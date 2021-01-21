#include <stdio.h>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,con=0,i,j;
	while(scanf("%d",&n)==1)
	{
		if(n==0) return 0;
		printf("case %d:\n",++con);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n-i;j++) printf(" ");
			for(j=1;j<=(i<<1)-1;j++) printf("%d",i);
			printf("\n");
		}
	}
	return 0;
}
