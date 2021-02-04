#include <cstdio>
#include <cstring>
using namespace std;
char s[2003][2003];
int n;
int col[10][2003],cole[10][2003];
int rol[10][2003],role[10][2003];

int maxx(int a,int b)
{
	if(a<0) a=-a;
	if(b<0) b=-b;
	if(a>b) return a;
	else return b;
}

int abs(int a)
{
	if(a<0) return -a;
	else return a;
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,x;
	scanf("%d",&time);
	while(time--)
	{
		memset(col,0,sizeof(col));
		memset(role,0,sizeof(role));
		memset(rol,0,sizeof(rol));
		memset(cole,0,sizeof(cole));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				x=s[i][j]^48;
				//printf("%d\n",x);
				if(col[x][i]==0)
					col[x][i]=j;
				else cole[x][i]=j;
				if(rol[x][j]==0)
					rol[x][j]=i;
				else role[x][j]=i;
			}
		for(int i=0;i<10;i++)
		{
			int max=0;
			for(int a=1;a<=n;a++)
			{
				if(rol[i][a]==0&&role[i][a]==0) continue;
				for(int b=1;b<=n;b++)
				{
					if(col[i][b]==0&&cole[i][b]==0) continue;
					int h=0,s=0;
					if(rol[i][a]!=0) h=abs(rol[i][a]-b);
					if(role[i][a]!=0) h=maxx(h,role[i][a]-b);
					if(col[i][b]!=0) s=maxx(col[i][b]-1,n-col[i][b]);
					if(cole[i][b]!=0) s=maxx(cole[i][b]-1,s),s=maxx(s,n-cole[i][b]);
					if(h*s>max) 
					{
						max=h*s;
					}
				}
			}
			for(int a=1;a<=n;a++)
			{
				if(col[i][a]==0&&cole[i][a]==0) continue;
				for(int b=1;b<=n;b++)
				{
					if(rol[i][b]==0&&role[i][b]==0) continue;
					int h=0,s=0;
					if(col[i][a]!=0) h=abs(col[i][a]-b);
					if(cole[i][a]!=0) h=maxx(h,cole[i][a]-b);
					if(rol[i][b]!=0) s=maxx(rol[i][b]-1,n-rol[i][b]);
					if(role[i][b]!=0) s=maxx(role[i][b]-1,s),s=maxx(s,n-role[i][b]);
					if(h*s>max) 
					{
						max=h*s;
					}
				}
			}
			printf("%d ",max);
		}
		printf("\n");
		//return 0;
	}
	return 0;
}