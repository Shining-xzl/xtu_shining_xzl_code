#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	srand(unsigned(time(0)));
	printf("10\n");
	for(int i=1;i<=10;i++)
	{
		int n,m,a,b,temp;
		n=rand()%5000+6;
		m=rand()%50000+1;
		printf("%d %d\n",n,m);
		while(m--)
		{
			a=rand()%n+1;
			b=a+rand()%100+1;
			if(b>n) b=n;
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}
