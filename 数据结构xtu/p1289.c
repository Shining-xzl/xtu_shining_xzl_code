#include <stdio.h>
const int w[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2,1};

int main()
{
	int T,temp,count = 0,i;
	scanf("%d", &T);
	char s[20];
	while(T--)
	{
		scanf("%s", s);
		temp = 0;
		for (i = 0; i < 18; ++i)
		{
			if(s[i] == 'X' || s[i] == 'x') s[i] = '0' + 10;
			s[i] -= '0';
			temp = temp + s[i] * w[i];
		}
		if(temp % 11 == 1)
			++count;
	}
	printf("%d\n", count);
	return 0;
}