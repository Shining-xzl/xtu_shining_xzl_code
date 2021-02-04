#include <cstdio>
using namespace std;

int abs(int x)
{
	if(x<0) return -x;
	else return x;
}

int main()
{
	// freopen("in.txt","r",stdin);
	int time,a,b,ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		ans=a+b;
		if(a!=b)
			ans+=abs(a-b)-1;
		printf("%d\n",ans);
	}
	return 0;
}