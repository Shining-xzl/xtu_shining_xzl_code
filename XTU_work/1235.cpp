#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int time,len,i;
	char s1[12],s2[12];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%s",s1,s2);
		len=strlen(s2);
		for(i=0;i<len;i++)
			printf("%c%c",s1[i],s2[len-i-1]);
		printf("%c\n",s1[len]);
	}
	return 0;
}
