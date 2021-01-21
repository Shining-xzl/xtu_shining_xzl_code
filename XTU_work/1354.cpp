#include <cstdio>
using namespace std;
const int TNT=1000000007;

int s[103][103];

void prime()
{
	int i,j,x,y;
	s[0][0]=1;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<=100;j++)
		{
			x=i-1;
			y=j-1;
			if(x>=0) s[i][j]+=s[x][j];
			if(s[i][j]>=TNT) s[i][j]-=TNT;
			if(y>=0) s[i][j]+=s[i][y];
			if(s[i][j]>=TNT) s[i][j]-=TNT;
			if(x>=0&&y>=0) s[i][j]+=s[x][y];
			if(s[i][j]>=TNT) s[i][j]-=TNT;
		}
	}
}

int main()
{
	prime();
	int time,a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",s[a][b]);
	}
	return 0;
}
