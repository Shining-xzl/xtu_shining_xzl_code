#include <cstdio>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int ans=0,n,a1,a2,a3;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&a1,&a2,&a3);
		if(a1+a2+a3>1) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
