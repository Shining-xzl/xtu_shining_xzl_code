#include <cstdio>
using namespace std;

char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	// freopen("in.txt","r",stdin);
	char a;
	int i;
	while(scanf("%c",&a)==1)
	{
		for(i=0;s[i]!='\0';i++)
				if(s[i]==a) break;
		if(s[i]=='\0')
			printf("%c",a);
		else printf("%c",s[i-1]);
	}
	return 0;
}