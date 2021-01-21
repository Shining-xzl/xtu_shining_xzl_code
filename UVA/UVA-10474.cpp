#include <cstdio>
#include <algorithm>
using namespace std;
const int T=10000;
int s[T+2];

bool cmp(const int &a,const int &b)
{
	return a<b;
}

int main()
{
	int n,m,i,x,con=0;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0) break;
		printf("CASE# %d:\n",++con);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		sort(s+1,s+n+1,cmp);
		while(m--)
		{
			scanf("%d",&x);
			i=lower_bound(s+1,s+n+1,x)-s;
			if(s[i]==x)
				printf("%d found at %d\n",x,i);
			else
				printf("%d not found\n",x);
		}
	}
	return 0;
}