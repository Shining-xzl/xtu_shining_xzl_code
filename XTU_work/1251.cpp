#include <cstdio>
using namespace std;

int main()
{
	int time,n,k,a,i;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=0;i<=90;i++)
		{
			a=n-i;
			k=n-i;
			if(a<0)
			{
				i=91;
				break;
			}
			while(k>0) 
			{
				a+=(k%10);
				k/=10;
			}
			if(a==n) break;
		}
		if(i>90) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
