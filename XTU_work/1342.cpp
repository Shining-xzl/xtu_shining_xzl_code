#include <stdio.h>
using namespace std;

void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}

int main()
{
	int time;
	int a,b,c;
	int a1,b1,c1;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&a,&b,&c);
		scanf("%d%d%d",&a1,&b1,&c1);
		if(a<b) swap(a,b);
		if(a<c) swap(a,c);
		if(b<c) swap(b,c);
		if(a1<b1) swap(a1,b1);
		if(a1<c1) swap(a1,c1);
		if(b1<c1) swap(b1,c1);
		if(a*b1==b*a1&&b*c1==c*b1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
