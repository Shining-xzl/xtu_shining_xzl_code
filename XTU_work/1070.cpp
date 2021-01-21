#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int a,b,c;
	scanf("%d",&a);
	c=a%10;
	b=a/10%10;
	a/=100;
	if((a==b&&b==c)||(a!=b&&b!=c&&a!=c)) printf("No");
	else printf("Yes");
	return 0;
}
