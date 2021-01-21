#include <stdio.h>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,con=0,m,i,j;
	while(scanf("%d",&n))
	{
		if(n==0) return 0;
		printf("Case %d:\n",++con);
		m=(n<<1)+n;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("XTU");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
