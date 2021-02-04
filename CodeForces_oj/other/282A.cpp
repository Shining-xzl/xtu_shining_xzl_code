#include <cstdio>
int ans,n;
char s[5];

int main()
{
	scanf("%d",&n);
	while(n--) 
	{
		scanf("%s",&s);
		if(s[1]=='+') ans++;
		else ans--;	
	}
	printf("%d\n",ans);
	return 0;
}
