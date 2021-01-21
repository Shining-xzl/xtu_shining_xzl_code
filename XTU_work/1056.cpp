#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[6],x[6];
	int m,A,B;
	while(scanf("%s",s)==1)
	{
		if(strlen(s)==1) break;
		scanf("%d",&m);
		while(m--)
		{
			A=0;
			B=0;
			scanf("%s",x);
			for(int i=0;i<4;i++)
				if(s[i]==x[i]) A++;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(i!=j&&s[i]==x[j])
						B++;
				}
			}
			printf("%dA%dB",A,B);
			if(m>0) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}