#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int time,len,ans,k;
	char s[40];
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",&s);
		len=strlen(s);
		ans=0;
		k=1;
		while(len)
		{
			len--;
			if(s[len]=='1') ans+=k;
			else if(s[len]=='-') ans-=k;
			k=(k<<1)+k;
		}
		printf("%d\n",ans);
	}
	return 0;
}
