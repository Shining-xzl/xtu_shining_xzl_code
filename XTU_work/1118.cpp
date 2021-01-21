#include <stdio.h>
using namespace std;

int main()
{
	int tim,a,b,c;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==0&&b==0&&c==0) printf("INF\n");
		else if(a==0&&b!=0) printf("1\n");
		else if(a==0&&b==0&&c!=0) printf("0\n");
		else if(b*b-4*a*c==0) printf("1\n");
		else if(b*b-4*a*c<0) printf("0\n");
		else printf("2\n");
	}
	return 0;
}
