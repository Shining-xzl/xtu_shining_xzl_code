#include <cstdio>
using namespace std;
char s[1003];

int main()
{
	int time,i;
	scanf("%d",&time);
	gets(s);
	while(time--)
	{
		gets(s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]-=5;
				if(s[i]<'A') s[i]+=26;
				if(s[i]>'Z') s[i]-=26; 
			}
		}
		puts(s);
	}
	return 0;
}
