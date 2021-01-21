#include <cstdio>
#include <cstring>
using namespace std;
const __int64 T=9223372036854775807;
__int64 ans[63][63],k[65],s[63];

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

int main()
{
	__int64 time,i,n,l,r,tempr,templ,anx;
	read(time);
	k[1]=1;
	for(i=2;i<=63;i++)
		k[i]=k[i-1]*2;
	while(time--)
	{
		read(n);
		for(i=1;i<=n;i++)
			read(s[i]);
		memset(ans,0,sizeof(ans));
		for(l=n-2;l>=0;l--)
		{
			for(i=1;i+l<=n;i++)
			{
				r=i+l;
				templ=T; 
				tempr=T;
				if(i-1>0) 
				{
					templ=s[i-1]*k[n-l-1];
					if(ans[i][r]==0||ans[i][r]>templ+ans[i-1][r])
					ans[i][r]=templ+ans[i-1][r];
				}
				if(r+1<=n) 
				{
					tempr=s[r+1]*k[n-l-1];
					if(ans[i][r]==0||ans[i][r]>tempr+ans[i][r+1])
					ans[i][r]=tempr+ans[i][r+1];
				}
			}
		}
		anx=T;
		for(i=1;i<=n;i++)
		{
			ans[i][i]+=k[n]*s[i];
			if(ans[i][i]<anx)
				anx=ans[i][i];
		}
		printf("%I64d\n",anx);
	}
	return 0;
} 
