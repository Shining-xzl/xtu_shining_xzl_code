#include <cstdio>
using namespace std;

void read(__int64 &a)
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

__int64 n,k;
__int64 a[1003],b[1003];

inline bool right(__int64 si)
{
	__int64 i,temp=k;
	for(i=1;i<=n;i++)
	{
		if(si*a[i]>b[i])
		{
			temp-=(si*a[i]-b[i]);
			if(temp<0) return 0;
		}
	}
	return 1;
}

__int64 work()
{
	__int64 l=0,r=2e+9,mid,ans=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if(right(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	__int64 time,i;
	read(time);
	while(time--)
	{
		read(n);
		read(k);
		for(i=1;i<=n;i++)
			read(a[i]);
		for(i=1;i<=n;i++)
			read(b[i]);
		i=work();
		printf("%I64d\n",i);
	}
	return 0;
} 
