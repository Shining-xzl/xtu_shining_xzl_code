#include <cstdio>
using namespace std;
char s[1003];
int n,i;
int a,b,c;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		a=0;
		b=0;
		c=0;
		scanf("%s",&s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='X') a++;
			else if(s[i]=='T') b++;
			else if(s[i]=='U') c++;
		}
		if(a>b) a=b;
		if(a>c) a=c;
		printf("%d\n",a);
	}
	return 0;
}
