#include <cstdio>
using namespace std;
//打表找规律 
int main()
{
	int ans,n,x;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		ans=0;
		x=1;
		do
		{
			if(x<=n) x=x<<1;
			else if(x>n) x=((x-n)<<1)-1;
			ans++;
		}while(x!=1);
		printf("%d\n",ans);
	}
	return 0;
}
