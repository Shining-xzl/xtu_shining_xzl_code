#include <cstdio>
using namespace std;

int main()
{
	int time;
	scanf("%d",&time);
	int n,x,y,k,i,a;
	while(time--)
	{
		scanf("%d%d%d",&n,&x,&y);
		k=y-x; 
		for(i=1;i<=k;i++)
			if(k%i==0&&k/i<=n-1)
				break;
		a=n-1-k/i;
		if(a<=x/i) a=x-a*i;
		else a=x-(x/i)*i;
		if(a==0) a=i; 
		while(n--)
		{
			printf("%d ",a);
			a+=i;
		}
		printf("\n");
	}
	return 0;
}
