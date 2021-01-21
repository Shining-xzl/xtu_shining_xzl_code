#include <cstdio>
using namespace std;

int main()
{
	int time,n,k,con,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		k=n%10;
		if(k==1||k==3||k==7||k==9)
		{
			k=n;
			x=0;
			con=0;
			while(k--)
			{
				con++;
				x=(x<<3)+(x<<1)+1;
				x%=n;
				if(x==0) break;
			}
			if(x==0) printf("%d\n",con);
			else printf("0\n");
		}
		else printf("0\n");
	}
	return 0;
} 
