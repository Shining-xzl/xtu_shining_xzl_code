#include <cstdio>
using namespace std;

int main()
{
	int x;
	scanf("%d",&x);
	printf("%d is ",x);
	if(x&1) printf("odd.");
	else printf("even.");
	return 0;
}