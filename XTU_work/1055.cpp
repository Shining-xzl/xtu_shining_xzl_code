#include <cstdio>
using namespace std;
char s[503];

int get_ans()
{
	int i=0,ans=0;
	while(s[i]!='\0')
	{
		ans+=s[i]-48;
		i++;
	}
	return ans;
}

int work(int n)
{
	int ans=0;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}

int main()
{
	int ans;
	while(scanf("%s",&s)==1)
	{
		ans=get_ans();
		if(ans==0) break;
		while(ans>9) ans=work(ans);
		printf("%d\n",ans);
	}
	return 0;
}
