#include <cstdio>
using namespace std;

int main()
{
	unsigned int n;
	int max,k,i,tim;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d",&n);
		max=0;
		if(n&1) k=1;
		else k=0;
		for(i=1;i<=31;i++)
		{
			if(n&(1<<i))
			{
				if(n&(1<<(i-1)))
					k++;
				else k=1;
			}
			if(k>max) max=k;
		}
		printf("%d\n",max);
	}
	return 0;
}
