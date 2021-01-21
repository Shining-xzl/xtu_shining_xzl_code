#include <cstdio>
using namespace std;
int s[10002],n;

void read(int &a)
{
	char c=getchar();
	a=0;
	while(c>'9'||c<'0') c=getchar();
	do
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
}

inline bool right()
{
	for(int i=3;i<=n;i++)
		if(s[i]+s[i-2]!=(s[i-1]<<1))
			return 0;
	return 1;
}

int main()
{
	int time,i;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			read(s[i]);
		if(right()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
