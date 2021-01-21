#include <cstdio>
using namespace std;

int s[12][12];
int n,m;
int temp[12][12];

void build()
{
	int i,j,op=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			s[i][j]=(++op);
	return;
}

void PR()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d",s[i][j]);
			if(j!=m-1) printf(" ");
		}	
		printf("\n");
	}
	printf("\n");
}

void TR()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			temp[j][i]=s[i][j];
	i=n;
	n=m;
	m=i;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			s[i][j]=temp[i][j];
	return;		
}

void SR(int l,int r)
{
	int i,tmp;
	for(i=0;i<m;i++)
	{
		tmp=s[r][i];
		s[r][i]=s[l][i];
		s[l][i]=tmp;
	}
	return;
}

void SC(int l,int r)
{
	int i,tmp;
	for(i=0;i<n;i++)
	{
		tmp=s[i][r];
		s[i][r]=s[i][l];
		s[i][l]=tmp;
	}
	return;
}

void FC()
{
	int i;
	for(i=0;i<(m>>1);i++)
		SC(i,m-i-1);
	return;
}

void FR()
{
	int i;
	for(i=0;i<(n>>1);i++)
		SR(i,n-i-1);
	return;
}

int main()
{
	char c[4];
	int l,r;
	while(scanf("%s",&c)==1)
	{
		if(c[0]=='I')
		{
			scanf("%d%d",&n,&m);
			build();
		}
		else if(c[0]=='P') PR();
		else if(c[0]=='T') TR();
		else if(c[0]=='S'&&c[1]=='R') 
		{
			scanf("%d%d",&l,&r);
			SR(l-1,r-1);
		}
		else if(c[0]=='S'&&c[1]=='C') 
		{
			scanf("%d%d",&l,&r);
			SC(l-1,r-1);
		}
		else if(c[0]=='F'&&c[1]=='R') FR();
		else if(c[0]=='F'&&c[1]=='C') FC();
	}
	return 0;
}
