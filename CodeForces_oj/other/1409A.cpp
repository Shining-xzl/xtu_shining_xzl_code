#include <cstdio>
using namespace std;

int main()
{
	int time,a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		if(a>b) a=a-b;
		else a=b-a;
		b=a/10;
		if(a%10!=0) b++;
		printf("%d\n",b);
	 } 
	return 0;
}
