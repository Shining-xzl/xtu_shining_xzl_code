#include <cstdio>
#include <cstring>

char s[103];

int main()
{
//	freopen("in.txt","r",stdin);
	int n,len;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",&s);
		len=strlen(s);
		if(len<=10)
			printf("%s\n",s);
		else printf("%c%d%c\n",s[0],len-2,s[len-1]);
	}
	return 0;
}
