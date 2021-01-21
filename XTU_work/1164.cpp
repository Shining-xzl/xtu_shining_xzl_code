#include <cstdio>
using namespace std;

int main()
{
	int i,ans;
	char s[1003];
	while(scanf("%s",s)==1)
	{
		ans=0;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='0') ans++;
			else if(s[i]=='4') ans++;
			else if(s[i]=='6') ans++;
			else if(s[i]=='8') ans+=2;
			else if(s[i]=='9') ans++;	
		}
		printf("%d\n",ans);
	}
	return 0;
} 
