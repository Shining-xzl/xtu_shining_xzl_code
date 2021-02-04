#include <cstdio>
using namespace std;

char s[1003];

int main()
{
	scanf("%s",&s);
	if(s[0]>='a') s[0]-=32;
	printf("%s\n",s);
	return 0;
}
