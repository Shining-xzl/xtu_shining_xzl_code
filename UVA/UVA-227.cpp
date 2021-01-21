#include <cstdio>
#include <cstring>
using namespace std;
char s[6][6];
int x,y;
int con=0;
bool flag;

void continu()
{
	for(int i=1; i<5; i++)
		gets(s[i]);
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
		{
			if(s[i][j]<'A'||s[i][j]>'Z')
			{
				x=i;
				y=j;
				s[i][j]=' ';
				return;
			}
		}
	return;
}

char k[1003];

int kp[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

void play(int len)
{
	int sign,x1,y1;
	if(k[len-1]=='0') len--;
	for(int i=0; i<len; i++)
	{
		if(k[i]=='A') sign=0;
		else if(k[i]=='B') sign=1;
		else if(k[i]=='L') sign=2;
		else if(k[i]=='R') sign=3;
		x1=x+kp[sign][0];
		y1=y+kp[sign][1];
		if(x1>=0&&x1<5&&y1>=0&&y1<5)
		{
			s[x][y]=s[x1][y1];
			s[x1][y1]=' ';
			x=x1;
			y=y1;
		}
		else
		{
			flag=0;;
			break;
		}
	}
}

void work()
{
	int len;
	con++;
	printf("Puzzle #%d:\n",con);
	flag=1;
	while(1)
	{
		gets(k);
		len=strlen(k);
		if(flag) play(len);
		if(k[len-1]=='0')
			break;
	}
	if(flag)
	{
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<4; j++)
			{
				printf("%c ",s[i][j]);
			}
			printf("%c\n",s[i][4]);
		}
	}
	else
	{
		printf("This puzzle has no final configuration.\n");
	}
}

int main()
{
	while(1)
	{
		gets(s[0]);
		if(s[0][0]=='Z')
			return 0;
		else continu();
		if(con) printf("\n");
		work();
	}
	return 0;
}
