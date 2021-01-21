#include <cstdio>
using namespace std;
char s[203];

int main()
{
	int time,a,l,i;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",&s);
		scanf("%d%d",&a,&l);
		for(i=0;i<a-1;i++) 
			printf("%c",s[i]);
		for(i=a+l-2;i>=a-1;i--)
			printf("%c",s[i]);
		for(i=a+l-1;s[i]!='\0';i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
