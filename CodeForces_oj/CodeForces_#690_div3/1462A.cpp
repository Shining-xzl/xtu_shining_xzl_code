#include <cstdio>

using namespace std;
int n;
int s[304];

int main()
{
	//freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		int l=1,r=n;
		while(l<=r)
		{
			printf("%d ",s[l++]);
			if(l<=r)
				printf("%d ",s[r--]);
		}
		printf("\n");
	}
	return 0;
}