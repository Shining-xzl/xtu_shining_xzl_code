#include <cstdio>
using namespace std;
void get_ans(int);

void get_ans(int n)
{
	int len=0,a=n,i;
	while(a>0) len++,a/=10;
	len=n-len*9;
	if(len<0) len=0;
	for(i=len;i<=n;i++)
	{
		a=len=i;
		while(a>0) len+=a%10,a/=10;
		if(len==n)
		{
			printf("%d\n",i);
			return;
		}
	}
	printf("0\n");
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	int i,n,s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s);
		get_ans(s);
	}
	return 0;
}
