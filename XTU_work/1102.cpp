#include <cstdio>
using namespace std;

int main()
{
	int tim,a,b,i;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d",&a,&b);
		a=a^b;
		b=0;
		for(i=0;i<=31;i++)
			if(a&(1<<i))
				b++;
		printf("%d\n",b);
	}
	return 0;
}
