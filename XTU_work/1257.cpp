#include <cstdio>
using namespace std;
__int64 ans[35][35];

int main()
{
	int n,m,time;
	ans[0][0]=1;
	for(n=1;n<=33;n++)
	{
		ans[n][0]=1;
		for(m=1;m<=33;m++)
			ans[n][m]=ans[n-1][m-1]+ans[n-1][m];	
	}
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		m=n-m;
		if((m<0)||(m&1))
			printf("0\n");
		else printf("%I64d\n",ans[n][m>>1]);
	}
	return 0;
}
