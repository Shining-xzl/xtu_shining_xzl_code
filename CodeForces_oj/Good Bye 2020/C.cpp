#include <cstdio>

using namespace std;
char s[100003];

int main()
{
//	freopen("in.txt","r",stdin);
	int time,ans,k;
	scanf("%d",&time);
	while(time--)
	{
		ans=0;
		scanf("%s",s);
		// printf("%s\n",s);
		for(int i=1;s[i]!=0;i++)
		{
			k=i-1;
			if(s[i]==s[k])
			{
				s[i]='*';
				ans++;
				continue;
			}
			k=i-2;
			if(k>=0&&s[k]==s[i])
			{
				s[i]='*';
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}