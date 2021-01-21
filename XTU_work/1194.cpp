#include <cstdio>
using namespace std;
const int MOD=1000000007;

__int64 ans[1003][1003];
__int64 mis[1003];

void get_ans()
{
	int i,j;
	ans[0][0]=1;
	for(i=1;i<=1000;i++)
	{
		ans[i][0]=1;
		for(j=1;j<=i;j++)
		{
			ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
			if(ans[i][j]>=MOD) ans[i][j]-=MOD;
		}
	}
	mis[0]=1;
	mis[1]=0;
	mis[2]=1;
	for(i=3;i<=1000;i++)
	{
		mis[i]=(i-1)*(mis[i-1]+mis[i-2])%MOD;
	}
}

int main()
{
	get_ans();
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n+m==0) break;
		printf("%I64d\n",ans[n][m]*mis[m]%MOD);
	}
	return 0;
}
