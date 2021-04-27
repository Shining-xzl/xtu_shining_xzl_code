#include <stdio.h>
const int p[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
int f[34][34];

int check(int x,int y)
{
	if(x > n || x <= 0 || y > m || y <= 0 || f[x][y] > 0) return 0;
	else return 1;
}

int main()
{
	scanf("%d %d", &n,&m);
	int count = 0, j = 0;
	int x = 1,y = 1,xx,yy;
	while(count < n*m)
	{
		f[x][y] = ++count;
		xx = x + p[j][0];
		yy = y + p[j][1];
		while(check(xx,yy) == 0 && count < n*m)
		{
			j = (j + 1) % 4;
			xx = x + p[j][0];
			yy = y + p[j][1];
		}
		x = xx;
		y = yy;
	}
	for(x = 1; x <= n; ++x)
	{
		for(y = 1; y <= m; ++y)
		{
			printf("%4d",f[x][y]);
		}
		printf("\n");
	}
	return 0;
}