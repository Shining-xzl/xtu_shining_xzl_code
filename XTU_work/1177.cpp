#include <cstdio>
using namespace std;
__int64 ans[35][35];

int main()
{
	int n,m;
	ans[0][0]=1;
	for(n=0;n<=33;n++)
	{
		for(m=0;m<=33;m++)
		{
			if(n==0&&m==0) continue;
			if(n-1>=0) ans[n][m]+=ans[n-1][m];
			if(m-1>=0) ans[n][m]+=ans[n][m-1]; 
		}
	}
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
		printf("%I64d\n",ans[n][m]);
	}
	return 0;
}
