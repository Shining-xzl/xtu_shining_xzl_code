#include <cstdio>
using namespace std;
int n;
int s[23];
int len;
int op[43],po;

int main()
{
	int time,i;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		len=0;
		po=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]); 
			if(s[i]!=s[i-1])
			{
				for(int j=1;j<=s[i]-s[i-1];j++)
					op[++po]=(++len);
				printf("1");
			}
			else printf("%d",len-op[po]+1);
			po--;
			if(i!=n) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
