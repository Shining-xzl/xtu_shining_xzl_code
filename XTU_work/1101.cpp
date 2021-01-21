#include <stdio.h>
using namespace std;
char s[303];

int main()
{
//	freopen("in.txt","r",stdin);
	int time,i;
	scanf("%d",&time);
	getchar();
	while(time--)
	{
		gets(s);
		for(i=0;s[i]!='\0';i++)
			if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
			else if(s[i]>='a'&&s[i]<='z') s[i]-=32;
			else continue;
		printf("%s\n",s);
	}
	return 0;
}
