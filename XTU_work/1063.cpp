#include <stdio.h>
using namespace std;
char s[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int a[10],len;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d,",n);
	while(n)
	{
		a[++len]=n%16;
		n>>=4;
	}
	for(int i=len;i>0;i--)
		printf("%c",s[a[i]]);
	return 0;
}
