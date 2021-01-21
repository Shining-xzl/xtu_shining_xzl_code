#include <cstdio>
using namespace std;

int main()
{
	int n,ans;
	while(scanf("%d",&n)==1)
	{
		if(n==-1) break;
		ans=(2+n)*(n-1)>>1;
		printf("%d\n",ans+2);
	}
	return 0;
}