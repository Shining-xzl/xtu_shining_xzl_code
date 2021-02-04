/*
The increment by one operation essentially allows us to change the parity of any position. 
Let's color the matrix like a chessboard. 
Since every pair of adjacent cells consist of cells with different colors, 
we can make values at all black cells even and values at all white cells odd.
*/
#include <cstdio>
#include <cstring>
using namespace std;

void work()
{	
	int n,m;
	int s[103][103];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&s[i][j]);
			if((i+j)&1)
			{	
				if((s[i][j]&1)!=1)
						s[i][j]++;
			}
			else if((s[i][j]&1)==1)
					s[i][j]++;
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
		work();
	return 0;
}