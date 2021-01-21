#include <cstdio>
using namespace std;

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

int s[10003];

int main()
{
	freopen("in.txt","r",stdin);
	int i,time,n,ans,temp;
	read(time);
	while(time--)
	{
		ans=2;
		temp=2;
		read(n);
		read(s[1]);
		read(s[2]);
		for(i=3;i<=n;i++)
		{
			read(s[i]);
			if(s[i]==s[i-1]+s[i-2])
			{
				temp++;
				if(temp>ans) ans=temp;
			}
			else temp=2;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
