#include <stdio.h>
using namespace std;

int main()
{
	int time;
	char a[6],b[6];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%s",&a,&b);
		if(a[0]==b[0]) printf("Draw\n");
		else if((a[0]=='r'&&b[0]=='s')||
		(a[0]=='s'&&b[0]=='p')||
		(a[0]=='p'&&b[0]=='r'))
			printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
