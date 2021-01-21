#include <cstdio>
using namespace std;
int n,m;
int s[12][12];
int temp[12];

void build()
{
	int i,j,op=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			s[i][j]=(++op);
		}
}

void move_row(int a,int l)
{
	int i,k;
	a--;
	for(i=0;i<n;i++)
	{
		k=i+l;
		if(k<0) k+=n;
		if(k>=n) k-=n;
		temp[k]=s[a][i];
	}
	for(i=0;i<n;i++)
		s[a][i]=temp[i];
}

void move_line(int a,int l)
{
	int i,k;
	a--;
	for(i=0;i<n;i++)
	{
		k=i+l;
		if(k<0) k+=n;
		if(k>=n) k-=n;
		temp[k]=s[i][a];
	}
	for(i=0;i<n;i++)
		s[i][a]=temp[i];
}

void out_put()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",s[i][j]);
			if(i!=n-1||j!=n-1)
			 printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	int time,a,l,i;
	char c[3];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		build();
		while(m--)
		{
			scanf("%s%d%d",&c,&a,&l);
			if(c[0]=='L') move_row(a,-l);
			else if(c[0]=='R') move_row(a,l);
			else if(c[0]=='U') move_line(a,-l);
			else move_line(a,l);
		}
		out_put();
	}
	return 0;
}
