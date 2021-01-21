#include <cstdio>
using namespace std;

int main()
{
	int time,ans,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		if(n>=100) ans=n<<1;
		else if(n<100) ans=3*n-100;
		printf("%d\n",ans);
	}
	return 0;
}
