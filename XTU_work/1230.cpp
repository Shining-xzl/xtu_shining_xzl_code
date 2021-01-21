#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	char s[10]; 
	while(scanf("%d%d%s",&n,&m,s)==3)
	{
		n-=m;
		if((n&1)||n<0) printf("Impossible\n");
		else if(m!=0&&s[0]=='D') printf("Impossible\n");
		else if(m==0&&s[0]!='D') printf("Impossible\n");
		else if(s[0]=='A') printf("%d:%d\n",(n>>1)+m,n>>1);
		else printf("%d:%d\n",n>>1,(n>>1)+m);
	}
	return 0;
} 
