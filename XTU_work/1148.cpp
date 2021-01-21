#include <cstdio>
using namespace std;
int a[102][102];
int s[103],n,ans;
void prime()
{
	int i,j;
	a[0][0]=1;
	for(i=1;i<=100;i++)
	{
		a[i][0]=1;
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			if(a[i][j]>=2013)
				a[i][j]-=2013; 
		}	
	}
}

int main()
{
	prime();
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
			ans+=s[i]*a[n-1][i];
			if(ans>=2013) ans%=2013;
		}
		printf("%d\n",ans);
	}
	return 0;
}
