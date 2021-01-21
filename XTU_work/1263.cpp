#include <cstdio>
#include <cstdlib>
using namespace std;
bool flag=0;

void read(int &a)//快读板子 
{
	char c=getchar();
	while(c>'9'||c<'0') 
	{
		if(c==EOF) exit(0);
		c=getchar();
	}
	a=0;
	while(c>='0'&&c<='9')
	{
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
}

char out[10];
int len;
void write(int a)//快输板子 
{
	len=0;
	out[0]='\n';
	if(a==0) out[++len]='0';
	while(a>0)
	{
		out[++len]=48+a%10;
		a/=10;
	}
	while(len>=0) putchar(out[len--]);
}

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4,S1,S2,SS;
	while(1)
	{
		read(x1); read(y1);
		read(x2); read(y2);
		read(x3); read(y3);
		read(x4); read(y4);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		if(x3>x4) swap(x3,x4);
		if(y3>y4) swap(y3,y4);
		S1=(x2-x1)*(y2-y1);
		S2=(x4-x3)*(y4-y3);
		if(y4>y1&&x4>x1&&y2>y3&&x2>x3)
		{
			if(x3>x1) x1=x3;
			if(y3>y1) y1=y3;
			if(y4<y2) y2=y4;
			if(x4<x2) x2=x4;
			SS=(x2-x1)*(y2-y1);
		}
		else SS=0;
		write(S1+S2-SS);
	}
	return 0;
} 
