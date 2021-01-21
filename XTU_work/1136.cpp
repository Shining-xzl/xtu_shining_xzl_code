#include <cstdio>
using namespace std;

int main()
{
	int time,x,n,a,b,sum;
	bool flag;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&n,&a,&b);
		flag=1;
		sum=0;
		a*=n;
		while(n--)
		{
			scanf("%d",&x);
			if(x<b) flag=0;
			sum+=x;
		}
		if(sum<a) flag=0;
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
