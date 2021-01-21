#include <cstdio>
using namespace std;

int main()
{
	int tim;
	int x1,x2,x3,y1,y2,y3;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(((x1-x2)*(y1-y3))==((y1-y2)*(x1-x3))) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
