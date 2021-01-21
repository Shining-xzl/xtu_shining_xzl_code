#include <cstdio>
using namespace std;

int main()
{
	int tim,x1,y1,x2,y2;
	scanf("%d",&tim);
	while(tim--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>y2||y1<x2) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
