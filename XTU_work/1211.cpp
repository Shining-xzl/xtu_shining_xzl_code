#include <cstdio>
using namespace std;
char s[20];
 
int main()
{
	int time,i,a,b,c;
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
		if(a+b==c) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
