#include <cstdio>
using namespace std;

int out[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
	int time,x,y,n,l,k;
	char s[10];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		x=0;
		y=0;
		k=0;
		while(n--)
		{
			scanf("%s",s);
			if(s[0]=='L') k--;
			else if(s[0]=='R') k++;
			else if(s[0]=='B') k+=2;
			else 
			{
				scanf("%d",&l);
				x+=l*out[k][0];
				y+=l*out[k][1];
			}
			if(k>3) k-=4;
			else if(k<0) k+=4; 
		}
		printf("%d %d\n",x,y);
	}
	return 0;
} 
