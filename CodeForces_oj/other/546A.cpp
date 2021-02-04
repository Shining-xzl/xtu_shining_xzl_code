#include <cstdio>
using namespace std;
int w,n,k;

int main()
{
	scanf("%d%d%d",&k,&n,&w);
	k=k*((1+w)*w>>1);
	if(k<=n) printf("0\n");
	else printf("%d\n",k-n);
	return 0;
 } 
