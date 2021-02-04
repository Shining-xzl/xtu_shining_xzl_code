#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int time;
	char s[103];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		printf("%d\n",strlen(s));
	}
	return 0;
}