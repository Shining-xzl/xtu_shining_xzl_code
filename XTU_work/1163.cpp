#include <cstdio>
using namespace std;
char s[10003];
int len = 0;
int main()
{
	// freopen("in.txt","r",stdin);
	char c;
	int i;
	while(scanf("%c", &c) == 1)	s[len++] = c;
	for (i = 0; i < len/16; ++i)
	{
		if (i) printf("\n");
		printf("%05X",i);
		for (int j = i * 16; j < (i+1)*16; ++j)
		{
			printf(" %02X",s[j]);
		}
	}
	if (len%16 != 0)
	{
		if (i) printf("\n");
		printf("%05X",i);
		for (int j = i * 16; j < len; ++j)
		{
			printf(" %02X",s[j]);
		}
	}
	return 0;
}