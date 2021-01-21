#include <cstdio>
#include <cstring>
using namespace std;
int n,ans;
char s[23][203];

void get(char pre[],char now[])
{
	int i,len=strlen(now);
	if(len>ans) len=ans;
	ans=0;
	for(i=0;i<len;i++)
		if(pre[i]==now[i]) ans++;
		else return;
}

int main()
{
	int time,i,j;
	scanf("%d",&time);
	for(i=1;i<=time;i++)
	{
		scanf("%d",&n);
		printf("Case %d: ",i);
		scanf("%s",&s[1]);
		ans=strlen(s[1]);
		for(j=2;j<=n;j++)
		{
			scanf("%s",&s[j]);
			get(s[j-1],s[j]);
		}
		for(j=0;j<ans;j++)
			printf("%c",s[n][j]);
		printf("\n");
	}
	return 0;
}
