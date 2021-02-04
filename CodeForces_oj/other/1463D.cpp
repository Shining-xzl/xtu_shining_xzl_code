#include <cstdio>

using namespace std;

int s[100004],n;

int main()
{
	freopen("in.txt","r",stdin);
	int time,l,r,con;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		l=0;
		r=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		s[0]=0;
		s[n+1]=n+1;
		con=0;
		for(int i=1;i<=n;i++)
		{
			con+=s[i]-s[i-1]-1;
			if(con>0) con--,l++;
		}
		con=0;
		for(int i=n;i>=1;i--)
		{
			con+=s[i+1]-s[i]-1;
			if(con>0) con--,r--;
		}
		printf("%d\n",r-l+1);
	}
	return 0;
}