#include <cstdio>
#include <cstring>
using namespace std;
int n,m,d;
int x,y,ex,ey;
bool k[103][103];
int a[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool f[103][103][4];
int ans;

void play()
{
	int tx,ty;
	ans=0;
	while(!f[x][y][d])
	{
		f[x][y][d]=1;
		if(x==ex&&y==ey)
			return;
		tx=x+a[d][0];
		ty=y+a[d][1];
		while(!k[tx][ty])
		{
			d++;
			if(d>3) d-=4;
			if(f[x][y][d]) 
			{
				ans=-1;
				return;
			}
			f[x][y][d]=1;
			tx=x+a[d][0];
			ty=y+a[d][1];
		}
		x=tx;
		y=ty;
		ans++;
	}
	ans=-1;
	return;
}

int main()
{
	int time,i,j;
	char s[103];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d",&n,&m,&d);
		memset(k,0,sizeof(k));
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(j=0;j<m;j++)
			{
				if(s[j]=='S')
				{
					x=i;
					y=j+1;
					k[i][j+1]=1;
				}
				else if(s[j]=='E')
				{
					ex=i;
					ey=j+1;
					k[i][j+1]=1;
				}
				else if(s[j]=='.') k[i][j+1]=1;
			}
		}
		d--;
		play();
		if(ans!=-1) printf("%d\n",ans);
		else printf("Impossible\n");
	}
	return 0;
} 
