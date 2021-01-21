#include <cstdio>
using namespace std;

int main()
{
	char s[1003];
	int ans,i,temp;
	while(scanf("%s",s)==1)
	{
		ans=1;
		temp=1;
		for(i=1;s[i]!='\0';i++)
		{
			if(s[i]==s[i-1]+1)
			{
				temp++;
				if(temp>ans)
					ans=temp;
			}
			else temp=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
