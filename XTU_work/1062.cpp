#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	char c;
	scanf("%c",&c);
	if(c>'Z') c-=32;
	else c+=32;
	printf("%c",c);
	return 0;
}
