#include <cstdio>
using namespace std;

char map[10][10];
int direction[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
bool now;

void find()
{
	char n,p;
	if(now) n='B',p='W';
	else p='B',n='W';
	int x,y,con,num=0;
	for(int i=1;i<9;i++)
		for(int j=1;j<9;j++)
		{
			if(map[i][j]=='B'||map[i][j]=='W') continue;
			for(int k=0;k<8;k++)
			{
				con=0;
				x=i+direction[k][0];
				y=j+direction[k][1];
				do
				{
					if(map[x][y]==n)
						con++;
					else break;
					x+=direction[k][0];
					y+=direction[k][1];
				}while(x>=1&&x<=8&&y>=1&&y<=8);
				if(con>0&&map[x][y]==p) 
				{
					if(num++) putchar(' ');
					printf("(%d,%d)",i,j);
					break;
				}
			}
		}
	if(num==0) printf("No legal move.\n");
	else printf("\n");
	return;
}

void work(int x,int y)
{
	bool ok=0;
	int xx,yy,con;
	char n,p;
	if(now) n='B',p='W';
	else p='B',n='W';
	for(int k=0;k<8;k++)
	{
		xx=x+direction[k][0];
		yy=y+direction[k][1];
		con=0;
		do
		{
			if(map[xx][yy]==n) con++;
			else break;
			xx+=direction[k][0];
			yy+=direction[k][1];
		}while(xx>=1&&xx<=8&&yy>=1&&yy<=8);
		if(con>0&&map[xx][yy]==p)
		{
			ok=1;
			map[x][y]=p;
			xx=x+direction[k][0];
			yy=y+direction[k][1];
			do
			{
				if(map[xx][yy]==n) map[xx][yy]=p;
				else break;
				xx+=direction[k][0];
				yy+=direction[k][1];
			}while(xx>=1&&xx<=8&&yy>=1&&yy<=8);
		}
	}
	if(ok==0)
	{
		now^=1;
		work(x,y);
	}
	else
	{
		int numw=0,numb=0;
		for(int i=1;i<9;i++)
			for(int j=1;j<9;j++)
				if(map[i][j]=='W') numw++;
				else if(map[i][j]=='B') numb++;
		printf("Black - %2d White - %2d\n",numb,numw);
	}
	return;
}

int main()
{
	int time,con=0;
	scanf("%d",&time);
	char command[4];
	while(time--)
	{
		if(con++) putchar('\n');
		for(int i=1;i<9;i++)
			scanf("%s",map[i]+1);
		scanf("%s",command);
		if(command[0]=='W') now=1;
		else now=0;
		while(scanf("%s",command)==1)
		{
			if(command[0]=='L') find();
			else if(command[0]=='M') work(command[1]-'0',command[2]-'0'),now^=1;
			else if(command[0]=='Q') 
			{
				for(int i=1;i<9;i++)
					printf("%s\n",map[i]+1);
				break;
			}
		}
	}
	return 0;
}