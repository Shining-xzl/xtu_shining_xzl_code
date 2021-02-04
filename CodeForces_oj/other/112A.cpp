#include <cstdio>
#include <cstring>
using namespace std;

char a[103],b[103];

void turn(char s[])
{
	int i,len=strlen(s);
	for(i=0;i<len;i++)
		if(s[i]>='a'&&s[i]<='z')
			s[i]-=32;
} 

int right()
{
	int i,len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]>b[i]) return 1;
		else if(a[i]<b[i]) return -1;
	}
	return 0;
}

int main()
{
	scanf("%s",&a);
	scanf("%s",&b);
	turn(a);
	turn(b);
	printf("%d\n",right());
	return 0;
}
