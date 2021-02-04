#include <cstdio>
using namespace std;
char s[56],ans;
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&s);
	for(int i=1;i<n;i++)
		if(s[i]==s[i-1]) ans++;
	printf("%d\n",ans);
	return 0;
}
