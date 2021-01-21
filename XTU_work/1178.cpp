#include <cstdio>
using namespace std;

int main()
{
	int time,temp,x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
		if(x1>x2)
		{
			temp=x1;
			x1=x2;
			x2=temp;
		}
		if(y1>y2)
		{
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if(x3>x4)
		{
			temp=x3;
			x3=x4;
			x4=temp;
		}
		if(y3>y4)
		{
			temp=y3;
			y3=y4;
			y4=temp;
		}
		if(x2>x3&&y2>y3&&x4>x1&&y4>y1)
		printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
