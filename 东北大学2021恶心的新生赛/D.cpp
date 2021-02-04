#include <cstdio>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time,n,k;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&k);
		if(n==1) printf("ma la se mi no.1!\n");
		else if(n<=k) printf("yo xi no forever!\n");
		else 
		{
			n-=1;
			if(n%(k+1)!=0) printf("yo xi no forever!\n");
			else printf("ma la se mi no.1!\n");
		}
	}
	return 0;
 } 
