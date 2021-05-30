#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 2e5+6;
char s[lim];
char k[lim];

int main()
{
	int T;
	scanf("%d", &T);
	int len,l,r;
	while(T--)
	{
		scanf("%s", s);
		len = strlen(s);
		l = r = 100003;
		k[l] = s[len-1];
		if(len > 1)
			k[++r] = s[len-2];
		for (int i = len-3; i >= 0; i--)
		{
			if (s[i] == k[l]) k[--l] = s[i];
			else k[++r] = s[i];
		}
		for (int i = l; i <= r; ++i)
			printf("%c",k[i]);
		printf("\n");
	}
	return 0;
}