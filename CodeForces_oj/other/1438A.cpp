#include <cstdio>
using namespace std;
int n;

void work()
{
	for(int i=1;i<=n;i++)
		printf("1 ");
	printf("\n");
}

int main()
{
	//freopen("in.txt","r",stdin);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		work();
	}
	return 0;
}