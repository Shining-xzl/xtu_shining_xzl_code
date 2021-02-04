#include <cstdio>
using namespace std;
const int LIM=2048;

int main()
{
	int k,l;
	scanf("%d",&k);
	printf("%d\n",k+LIM-1);
	l=1;
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<l;j++)
		{
			printf("1 %d\n",i);
		}
		l<<=1;
	}
	l=LIM/k;
	for(int i=0;i<k;i++)
	{
		printf("2 %d",l);
		for(int j=0;j<l;j++)
		{
			printf(" 11");
		}
		printf("\n");
	}
	return 0;
 } 
