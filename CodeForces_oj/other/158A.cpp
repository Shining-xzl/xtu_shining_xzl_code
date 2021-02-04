#include <cstdio>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,a,b;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%d",&a);
		if(!a) 
		{
			printf("%d\n",i-1);
			return 0;
		}
	}
	i=k;
	while(scanf("%d",&b)&&a==b&&i<n) i++;
	printf("%d\n",i);
	return 0;
}
