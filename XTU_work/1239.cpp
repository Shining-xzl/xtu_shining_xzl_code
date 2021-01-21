#include <cstdio>
using namespace std;
int s[6][6];
char c[7];

void change1(int a,int l)
{
	int i,j,b,p,o=a;
	for(i=1;i<=4;i++)
	{
		b=0;
		p=o;
		a=o;
		for(j=1;j<=4;j++)
		{
			if(s[i][a]!=0)
			{

				if(b==0)
				{
					s[i][p]=s[i][a];
					b=s[i][a];
					if(p!=a) s[i][a]=0;
				}
				else if(b==s[i][a])
				{
					s[i][a]=0;
					s[i][p]*=2;
					b=0;
					p+=l;
				}
				else
				{
					b=s[i][a];
					p+=l;
					s[i][p]=b;
					if(p!=a) s[i][a]=0;
				}
			}
			a+=l; 
		}
	}
}

void change2(int a,int l)
{
	int i,j,b,p,o=a;
	for(i=1;i<=4;i++)
	{
		b=0;
		p=o;
		a=o;
		for(j=1;j<=4;j++)
		{
			if(s[a][i]!=0)
			{

				if(b==0)
				{
					s[p][i]=s[a][i];
					b=s[a][i];
					if(p!=a) s[a][i]=0;
				}
				else if(b==s[a][i])
				{
					s[a][i]=0;
					s[p][i]*=2;
					b=0;
					p+=l;
				}
				else
				{
					b=s[a][i];
					p+=l;
					s[p][i]=b;
					if(p!=a) s[a][i]=0;
				}
			}
			a+=l; 
		}
	}
}

int main()
{
	int time,i,j;
	scanf("%d",&time);
	while(time--)
	{
		for(i=1;i<=4;i++)
			for(j=1;j<=4;j++)
				scanf("%d",&s[i][j]);
		scanf("%s",c);
		if(c[0]=='L') change1(1,1);
		else if(c[0]=='R') change1(4,-1);
		else if(c[0]=='U') change2(1,1);
		else if(c[0]=='D') change2(4,-1);  
		for(i=1;i<=4;i++)
			printf("%d %d %d %d\n",s[i][1],s[i][2],s[i][3],s[i][4]);
		printf("\n");
	}
	return 0;
}
