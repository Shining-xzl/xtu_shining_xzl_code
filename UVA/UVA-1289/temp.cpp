#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <time.h>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	printf("50\n");
	int q[54];
	srand((unsigned)time(0));
	for(int i=1;i<=50;i++)
	{
		printf("50 ");
		int x;
		for(int j=1;j<=50;j++)
		{
			x=rand()%10000;
			q[j]=x;
		}
		sort(q+1,q+51);
		for(int j=1;j<=50;j++)
			printf("%d ",q[j]);
		printf("\n"); 
	}
	return 0;
 } 
