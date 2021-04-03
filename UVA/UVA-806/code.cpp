#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int lim = 66;
char quadtree[lim][lim];
int n;
int num[64 * 64 +6],len;
int xcount[lim][lim];

int get_count(int sx,int sy,int ex,int ey)
{
	--sx;
	--sy;
	return xcount[ex][ey] + xcount[sx][sy] - xcount[sx][ey] - xcount[ex][sy]; 
}

void dfs(int k,int sx,int sy,int ex,int ey,int all)
{
	int now = get_count(sx,sy,ex,ey);
	// printf("***%d  %d %d %d %d %d\n", now,sx,sy,ex,ey,all);
	if(now == 0) return;
	else if(all == now)
	{
		num[len++] = k;
		return;
	}
	int midx = (sx + ex) >> 1;
	int midy = (sy + ey) >> 1;
	all >>= 2;
	dfs(k * 5 + 1,sx,sy,midx,midy,all);
	dfs(k * 5 + 2,sx,midy + 1,midx,ey,all);
	dfs(k * 5 + 3,midx + 1,sy,ex,midy,all);
	dfs(k * 5 + 4,midx + 1,midy + 1,ex,ey,all);
}

void process_val(int &a)
{
	int b = 0;
	do
	{
		b = b*5 + a%5;
		a /= 5;
	}while(a > 0);
	a = b;
}

void process_map()
{
	len = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%s", quadtree[i] + 1);
	memset(xcount, 0, sizeof(xcount));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			xcount[i][j] = xcount[i][j-1];
			if(quadtree[i][j] == '1')
				++xcount[i][j];
		}
		for (int j = 1; j <= n; ++j)
			xcount[i][j] += xcount[i-1][j];
	}
	// printf("n = %d\n", n);
	dfs(0,1,1,n,n,n*n);
	for (int i = 0; i < len; ++i)
		process_val(num[i]);
	sort(num,num + len);
	for (int i = 0; i < len; ++i)
	{
		if((i+1)%12 == 0 || i == len - 1)
			printf("%d\n",num[i]);
		else printf("%d ", num[i]);
	}
	printf("Total number of black nodes = %d\n", len);
	
}

void draw(int sx,int sy,int ex,int ey,int x)
{
	if(x == 0)
	{
		for (int i = sx; i <= ex; ++i)
			for (int j = sy; j <= ey; ++j)
				quadtree[i][j] = 1;
		return;
	}
	int now = x%5; 
	x /= 5;
	int midx = (sx + ex) >> 1;
	int midy = (sy + ey) >> 1;
	if(now == 1) draw(sx,sy,midx,midy,x);
	else if(now == 2) draw(sx,midy + 1,midx,ey,x);
	else if(now == 3) draw(midx + 1,sy,ex,midy,x);
	else if(now == 4) draw(midx + 1,midy + 1,ex,ey,x);

}

void process_num()
{
	n = -n;
	len = 0;
	while(scanf("%d",&num[len]) == 1 && num[len] != -1) ++len;
	for (int i = 0; i < len; ++i)
		draw(1,1,n,n,num[i]);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%c",quadtree[i][j] ? '*' : '.');
		printf("\n");
	}
}

int main()
{
	int Case = 0;
	while(scanf("%d",&n) == 1 && n)
	{
		if(Case) printf("\n");
		printf("Image %d\n", ++Case);
		memset(quadtree, 0, sizeof(quadtree));
		if(n < 0) process_num();
		else process_map();	
	}
	return 0;
} 
