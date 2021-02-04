#include <cstdio>

using namespace std;
long long s[200005];
int n;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	long long ans;
	long long max,temp1,temp2,temp;
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&s[i]);
		ans=0;
		for(int i=1;i<n;i++)
		{
			temp=s[i]-s[i+1];
			if(temp<0) temp=-temp;
			ans+=temp;
		}
		max=0;
		if(n>=3)
		{
			max=s[1]-s[2];
			if(max<0) max=-max;
		}
		for(int i=2;i<n;i++)
		{
			temp1=s[i]-s[i+1];
			temp2=s[i]-s[i-1];
			temp=s[i+1]-s[i-1];
			if(temp<0) temp=-temp;
			if(temp1<0) temp1=-temp1;
			if(temp2<0) temp2=-temp2;
			temp1+=temp2;
			temp=temp1-temp;
			if(temp>max) 
			{
				max=temp;
			}
		}
		if(n>=3)
		{
			temp=s[n]-s[n-1];
			if(temp<0) temp=-temp;
			if(temp>max) max=temp;
		}
		if(n==2||n==1) ans=0;
		printf("%lld\n",ans-max);
	}
	return 0;
}