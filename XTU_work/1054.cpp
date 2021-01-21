#include <cstdio>
using namespace std;
int s[1003];
int n,ans;

int main()
{
	int i,j;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		for(i=0;i<n;i++)
			scanf("%d",&s[i]);
		ans=0;
		for(i=0;i<n;i++)
		{
			if(s[i]>10000) continue;
			for(j=0;j<n;j++)
				if(s[i]*s[i]==s[j])
				{
					ans++;
					//break;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
