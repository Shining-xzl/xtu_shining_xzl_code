#include <cstdio>
using namespace std;

int main()
{
	int time,a1,b1,c1,a2,b2,c2,ax,bx,k,s;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&a1,&b1,&c1);
		scanf("%d%d%d",&a2,&b2,&c2);
		ax=a1+b1+c1;
		bx=a2+b2+c2;
		if(a1==b1&&b1==c1)
		{
			if(a1==1) ax=70000;
			else ax=a1*10000;
		}
		else if(a1==b1||b1==c1||a1==c1)
		{
			if(a1==b1) k=a1,s=c1;
			else if(b1==c1) k=b1,s=a1;
			else if(a1==c1) k=a1,s=b1;
			if(s==1) s=7;
			if(k==1) k=7;
			ax=k*1000+s;
		}
		if(a2==b2&&b2==c2)
		{
			if(a2==1) bx=70000;
			else bx=a2*10000;
		}
		else if(a2==b2||b2==c2||a2==c2)
		{
			if(a2==b2) k=a2,s=c2;
			else if(b2==c2) k=b2,s=a2;
			else if(a2==c2) k=a2,s=b2;
			if(s==1) s=7;
			if(k==1) k=7;
			bx=k*1000+s;
		}
		if(ax>bx) printf("Alice\n");
		else if(ax<bx) printf("Bob\n");
		else printf("Draw\n");
	}
	return 0;
} 
