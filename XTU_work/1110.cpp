#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int n,s[103],i,num;
	while(scanf("%d",&n)&&n)
	{
		num=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			if(s[i]&1) num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
