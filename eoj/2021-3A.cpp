#include <cstdio>
#include <cstdlib>
using namespace std;
int stand;

void ans(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int ask(int pos)
{
	int x;
	printf("? %d\n",pos);
	fflush(stdout);
	scanf("%d",&x);
	if(x==stand) ans(pos);
	fflush(stdout);
	return x;
}


int main()
{
	int n;
	scanf("%d",&n);
	fflush(stdout);
	int l=1,r=1<<n,mid;	
	stand=r;
	int a,b,c,d;
	if(n==1)
	{
		a=ask(1);
		if(a==2) ans(1);
		else ans(2);
	}
	a=ask(l);
	b=ask(r);
	while(l<=r)
	{
		mid=(l+r)>>1;
		c=ask(mid);
		d=ask(mid+1);
		if((a<b)==(c<d))
		{
			if(a<b) l=mid+1,a=d;
			else r=mid,b=c;
		}
		else
		{
			if(a<b)
			{
				if(c>a) r=mid,b=c;
				else l=mid+1,a=d;
			}
			else
			{
				if(a>c) r=mid,b=c;
				else l=mid+1,a=d;
			}
		}
	}
	return 0;
}