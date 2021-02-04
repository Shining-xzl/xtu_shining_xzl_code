#include <cstdio>
using namespace std;
char s[200003];
int main()
{
	freopen("in.txt","r",stdin);
	int time;
	int ans;
	int a,b;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",s);
		a=0;
		b=0;
		ans=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='(') a++;
			if(s[i]=='[') b++;
			if(s[i]==')'&&a>0) ans++,a--;
			if(s[i]==']'&&b>0) ans++,b--;  
		}
		printf("%d\n",ans);
	}
	return 0;
}