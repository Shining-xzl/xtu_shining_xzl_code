#include <cstdio>
#include <cstring>
using namespace std;
int x[10];

int main()
{
	int time;
	int n,k,ans,temp,xx;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&k);
		memset(x,0,sizeof(x));
		for(int i=9;i>0;i--)
			x[i*k%10]=i;
		ans=0;
		while(n>=k)
		{
			if(n%10==0)
			{
				do
				{
					n/=10;
				}while(n%10==0);
				ans++;
			}
			else 
			{
				xx=x[n%10];
				temp=n/k;
				if(xx>0)
				{
					if(xx>temp)
						ans+=temp,n%=k;
					else ans+=xx,n-=xx*k;
				}
				else
				{
					ans+=temp;
					n%=k;
				}
			}
		}
		printf("%d %d\n",ans,n);
	}
	return 0;
}