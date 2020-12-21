#include <cstdio>

using namespace std;
int n;
char s[203];

int main()
{
	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%s",&n,s+1);
		if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[4]=='0')
		{
			printf("YES\n");
		}
		else if(s[1]=='2'&&s[2]=='0'&&s[3]=='2'&&s[n]=='0')
		{
			printf("YES\n");
		}
		else if(s[1]=='2'&&s[2]=='0'&&s[n-1]=='2'&&s[n]=='0')
		{
			printf("YES\n");
		}
		else if(s[1]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0')
		{
			printf("YES\n");
		}
		else if(s[n-3]=='2'&&s[n-2]=='0'&&s[n-1]=='2'&&s[n]=='0')
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}