#include <stdio.h>
using namespace std;
const int TNT=200;
int n;
int s[TNT+2];
int stack[TNT+2];

int main()
{
	int t,len,con,i;
	bool flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		len=con=0;
		flag=1;
		for(i=1;i<=n;i++)
		{
			while(stack[len]!=s[i]&&con<n) stack[++len]=(++con);
			if(stack[len]!=s[i])
			{
				flag=0;
				break;
			}
			else len--;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
