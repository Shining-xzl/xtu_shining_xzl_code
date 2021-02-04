#include <cstdio>
#include <cstring>
using namespace std;
bool k[256];
short num,len;
char name[103];
int main()
{
	memset(k,0,sizeof(k));
	scanf("%s",&name);
	len=strlen(name);
	for(short i=0;i<len;i++)
		if(!k[name[i]]) num++,k[name[i]]=1;
	if(num&1)
		printf("IGNORE HIM!\n");
	else printf("CHAT WITH HER!\n");
	return 0;
}
