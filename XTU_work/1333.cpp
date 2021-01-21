#include <cstdio>
using namespace std;

int main()
{
	int time,a,b,c;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&a,&b,&c);
		c-=a;
		if(c<=0) printf("0\n");
		else if(c%b==0) printf("%d\n",c/b);
		else printf("%d\n",c/b+1);
	}
	return 0;
}
