#include <cstdio>
using namespace std;
__int64 ans[45];

void get()
{
	ans[0]=0;
	ans[1]=2;
	ans[2]=3;
	for(int i=3;i<=40;i++)
		ans[i]=ans[i-1]+ans[i-2];
}

int main()
{
	get();
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		printf("%I64d\n",ans[n]);
	}
	return 0;
}
