#include <cstdio>
#include <algorithm>
using namespace std;

struct st
{
	int x1,x2;
}s[10003];

bool cmp(const st &a,const st &b)
{
	return a.x1<b.x1;
}

void read(int &a)
{
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	a=0;
	while(c<='9'&&c>='0')
	{
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
	return;
}

int main()
{
	int i,ans,l,r,n;
	read(n);
	if(n==0) return 0;
	do
	{
		for(i=1;i<=n;i++)
		{
			read(s[i].x1);
			read(s[i].x2);
		}
		sort(s+1,s+n+1,cmp);
		ans=0;
		l=s[1].x1;
		r=s[1].x2;
		for(i=2;i<=n;i++)
		{
			if(s[i].x1<=r)
			{
				if(s[i].x2>r)
					r=s[i].x2;
			}
			else
			{
				ans+=r-l;
				l=s[i].x1;
				r=s[i].x2;
			}
		}
		ans+=r-l;
		printf("%d\n",ans); 
		read(n);
	}while(n);
	return 0;
} 
