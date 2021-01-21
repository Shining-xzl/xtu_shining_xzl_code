#include <cstdio>
using namespace std;
__int64 ans[62][62];
//µÝÍÆ 
void prime()
{
	int i,j;
	ans[0][30]=1;
	for(i=1;i<=60;i++)
		for(j=1;j<=61;j++)
			ans[i][j]=ans[i-1][j]+ans[i-1][j-1]+ans[i-1][j+1]; 

}

int main()
{
	prime();
	int time,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		printf("%I64d\n",ans[n][30]);
	}
	return 0;
}
