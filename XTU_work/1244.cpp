#include <cstdio>
#include <algorithm>
using namespace std;
int s[10003];
int n,m,sum,mn;

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

bool cmp(const int &a,const int &b)
{
	return a>b;
}

bool right(int si)
{
	int sum,con=0,i=1;
	while(i<=n)
	{
		con++;
		sum=s[i++];
		while(sum+s[i]<=si&&i<=n) sum+=s[i++];
	}
	if(con<=m) return 1;
	else return 0;
}

int work()
{
	int ans,mid,i,l,r;
	r=sum;
	l=mn;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(right(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,i;
	read(time);
	while(time--)
	{
		sum=0;
		mn=0;
		read(n);
		read(m);
		for(i=1;i<=n;i++)
		{
			read(s[i]);
			if(s[i]>mn) mn=s[i];
			sum+=s[i];
		}
		i=work();
		printf("%d\n",i);
	}
	return 0;
} 
