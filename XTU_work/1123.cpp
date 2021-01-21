#include <cstdio>
using namespace std;
int s[1003];
int n,k;

int get()
{
	int i;
	for(i=n-1;i>=k;i--)
		if(s[i+1]!=s[i]) return -1;
	for(i=k-1;i>=1;i--)
		if(s[i]!=s[i+1]) return i;
	return 0;
} 

int main()
{
	int time,i;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		printf("%d\n",get());
	}
	return 0;
}
