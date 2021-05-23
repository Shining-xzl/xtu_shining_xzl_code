#include <cstdio>
#include <cstring>
using namespace std;

char view[7][13][13];
char color[13][13][13];

char read()
{
	char c = getchar();
	while((c < 'A' || c > 'Z') && c != '.') c = getchar();
	return c;
}
int n;

void dir_pos(int l,int a,int b,int dep,int &x,int &y,int &z) // 坐标的转换
{
	if (l == 0) {z = dep; x = a; y = b;}
	else if(l == 1) {z = n+1-b; x = a; y = dep;}
	else if(l == 2) {z = n+1-dep; x = a; y = n+1-b;}
	else if(l == 3) {z = b; x = a; y = n+1-dep;}
	else if(l == 4) {z = n+1-a; x = dep ; y = b;}
	else if(l == 5) {z = a; x = n+1-dep ; y = b;}
	return;	
}

int main()
{
	// freopen("in.txt","r",stdin);
	int xp,yp,zp;
	while(scanf("%d",&n) == 1 && n)
	{
		memset(color,0,sizeof(color));
		for(int i = 1; i <= n; ++i)
			for (int j = 0; j < 6; ++j)
				for (int k = 1; k <= n; ++k)
					view[j][i][k] = read();


		for (int i = 0; i < 6; ++i) // 击穿
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= n; ++y)
					if(view[i][x][y] == '.')
					{
						for (int dep = 1; dep <= n; ++dep)
						{
							dir_pos(i,x,y,dep,xp,yp,zp);
							color[zp][xp][yp] = '.';
						}
					}


		bool conflict = 1;
		while(conflict) // 染色并处理冲突，一次染色，产生冲突，便继续染色
		{
			conflict = 0;
			for (int i = 0; i < 6; ++i)
				for (int x = 1; x <= n; ++x)
					for (int y = 1; y <= n; ++y)
					{
						if (view[i][x][y] == '.') continue;
						for (int dep = 1; dep <= n; ++dep)
						{
							dir_pos(i,x,y,dep,xp,yp,zp);
							if (color[zp][xp][yp] == '.') continue;
							if (color[zp][xp][yp] == 0) 
							{
								color[zp][xp][yp] = view[i][x][y];
								break;
							}
							if(color[zp][xp][yp] == view[i][x][y]) break;
							color[zp][xp][yp] = '.';
							conflict = 1;
						}
					}
		}
		int count = n * n * n;
		for (int z = 1; z <= n; ++z)
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= n; ++y)
					if(color[z][x][y] == '.')
						--count;
		printf("Maximum weight: %d gram(s)\n", count);
	}
	return 0;
}