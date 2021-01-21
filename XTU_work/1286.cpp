#include <cstdio>
using namespace std;
__int64 k[102];

int main()
{
	int i;
	k[0]=1;
	k[1]=2;
	k[2]=3;
	for(i=3;i<=86;i++)
		k[i]=k[i-1]+k[i-2];
	__int64 n;
	while(scanf("%I64d",&n)==1)
	{
		for(i=0;k[i]<n;i++); 
		if(k[i]>n) i--;
		printf("%d\n",i);	
	}
	return 0;
} 
