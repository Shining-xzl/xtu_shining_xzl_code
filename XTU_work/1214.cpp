#include <cstdio>
using namespace std;
const int TNT=1e+9;

int ans(int a,int b,int c)
{
	int i,k;
	for(i=0,k=1;k<=TNT&&a*k<=TNT;k*=10,i++)
	{
		if(a*k+b==c) return i;
		if(k==TNT) break;
	}
	for(i=0,k=1;k<=TNT&&b*k<=TNT;k*=10,i++)
	{
		if(b*k+a==c) return -i;
		if(k==TNT) break;
	}
}

int main()
{
	int i,time,a,b,c;
	char s[30];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		a=0;
		for(i=0;s[i]!='+';i++)
			a=(a<<3)+(a<<1)+s[i]-48;
		b=0;
		for(i++;s[i]!='=';i++)
			b=(b<<3)+(b<<1)+s[i]-48;
		c=0;
		for(i++;s[i]!='\0';i++)
			c=(c<<3)+(c<<1)+s[i]-48;
		printf("%d\n",ans(a,b,c));
	}
	return 0;
}
