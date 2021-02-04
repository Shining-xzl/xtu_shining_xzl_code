#include <cstdio>

using namespace std;

int main()
{
	int time;
	int n,m,r,l,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d%d",&n,&m,&r,&l);
		ans=r+l-2;
		if(n+m-r-l>ans) ans=n-r+m-l;
		if(r-1+m-l>ans) ans=r-1+m-l;
		if(l-1+n-r>ans) ans=l-1+n-r;
		printf("%d\n",ans);
	}
	return 0;
}