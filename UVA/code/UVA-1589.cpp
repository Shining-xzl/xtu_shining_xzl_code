#include <cstdio>
using namespace std;
int n,xx,yy;
struct chese
{
	char c;
	int x,y;
}red[9];

int op[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int poo;
int abs(int x)
{
	if(x<0) return -x;
	else return x;
}

bool check_H(int x1,int y1,int x2,int y2)
{
	if((abs(x1-x2)==2&&abs(y1-y2)==1)||(abs(x1-x2)==1&&abs(y1-y2)==2))
	{
		int lx=x1-x2,ly=y1-y2;
		if(abs(lx)==2)
		{
			if(lx>0) lx--;
			else lx++;
		}
		else
		{
			if(ly>0) ly--;
			else ly++;
		}
		x2=x1-lx;
		y2=y1-ly;
		for(int j=1;j<=n;j++)
			if(red[j].x==x2&&red[j].y==y2)
				return 0;
		return 1;
	}
	else return 0;
}

bool check()
{
	int tx,ty;
	bool flag=1;
	int con;
	if(poo!=0)
	{

		tx=red[poo].x;
		ty=red[poo].y;
		for(int i=1;i<=n;i++)
			if(red[i].y==yy&&tx>red[i].x&&xx<red[i].x)
				flag=0;
		if(flag) return false;
	}
	for(int i=0;i<4;i++)
	{
		flag=1;
		tx=xx+op[i][0];
		ty=yy+op[i][1];
		if(tx>3||tx<1) {flag=0;continue;}
		if(ty>6||ty<4) {flag=0;continue;}
		for(int j=1;j<=n;j++)
		{
			switch(red[j].c)
			{
				case 'G':
				if(ty==red[j].y)
				{
					flag=0;
					for(int k=1;k<=n;k++)
						if(red[k].y==ty&&red[k].x>tx&&red[k].x<red[j].x)
							flag=1;
				}
				break;
				case 'H':
				if(check_H(tx,ty,red[j].x,red[j].y))
					flag=0;
				break;
				case 'R':
				if(ty==red[j].y&&tx==red[j].x)
					flag=1;
				else if(ty==red[j].y)
				{
					flag=0;
					for(int k=1;k<=n;k++)
						if(red[k].y==ty&&((red[k].x>red[j].x&&tx>red[k].x)||(red[k].x<red[j].x&&tx<red[k].x)))
							flag=1;

				}
				else if(tx==red[j].x)
				{
					flag=0;
					for(int k=1;k<=n;k++)
						if(red[k].x==tx&&((red[k].y>red[j].y&&ty>red[k].y)||(red[k].y<red[j].y&&ty<red[k].y)))
							flag=1;

				}

				break;
				case 'C':
				con=0;
				if(ty==red[j].y)
				{	
					for(int k=1;k<=n;k++)
						if(ty==red[k].y&&((tx>red[k].x&&red[j].x<red[k].x)||(tx<red[k].x&&red[j].x>red[k].x)))
							con++;
				}
				else if(tx==red[j].x)
				{
					for(int k=1;k<=n;k++)
						if(tx==red[k].x&&((ty>red[k].y&&red[j].y<red[k].y)||(ty<red[k].y&&red[j].y>red[k].y)))
							con++;
				}
				if(con==1) flag=0;
				break;
			}
			if(!flag) break;
		}
		if(flag) break;
	}
	if(flag) return false;
	else return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char temp[3];
	while(scanf("%d%d%d",&n,&xx,&yy)==3)
	{
		poo=0;
		if(n==0&&xx==0&&yy==0) break;
		for(int i=1;i<=n;i++)
		{
			scanf("%s%d%d",temp,&red[i].x,&red[i].y);
			red[i].c=temp[0];
			if(temp[0]=='G'&&red[i].y==yy) poo=i;
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}