#include <cstdio>
using namespace std;
int ans[35][35];

void prime()
{
	int i,j;
	ans[0][0]=1;
	for(i=1;i<=33;i++)
	{
		ans[i][0]=1;
		for(j=1;j<=i;j++)
			ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
	}
}

int main()
{
	prime();
	int n,i;
	while(scanf("%d",&n)==1)
	{
		if(n<0) break;
		printf("2^%d=",n);
		printf("%d",ans[n][0]);
		for(i=1;i<=n;i++)
			printf("+%d",ans[n][i]);
		printf("\n");
	}
	return 0;
}
