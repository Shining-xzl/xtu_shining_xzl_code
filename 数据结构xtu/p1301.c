#include <stdio.h>
const int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2,1};

int main()
{
	int T,temp,i;
	char s[20];
	scanf("%s", s);
	temp = 0;
	for (i = 0; i < 17; ++i)
	{
		s[i] -= '0';
		temp = temp + s[i] * w[i];
	}
	temp %= 11;
	temp = 12 - temp;
	temp %= 11;
	if(temp == 10)
		printf("X\n");
	else printf("%d\n", temp);
	return 0;
}