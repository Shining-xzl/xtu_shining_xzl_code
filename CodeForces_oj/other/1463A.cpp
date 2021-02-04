#include <cstdio>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	int a,b,c,sum;
	while(time--)
	{
		scanf("%d%d%d",&a,&b,&c);
		sum=a+b+c;
		if(a>b) a=b;
		if(a>c) a=c;
		if(sum%9==0&&a>=sum/9) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}