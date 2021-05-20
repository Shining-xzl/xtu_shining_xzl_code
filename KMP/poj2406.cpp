#include <cstdio>
#include <cstring>
using namespace std;

const int lim = 1e6+3;

char s[lim];
int next[lim];

int main()
{
	int j,len;
	while(scanf("%s",s) == 1)
	{
		len = strlen(s);
		if(len == 1 && s[0] == '.') break;
		next[0] = j = -1;
		for (int i = 0; i < len; ++i)
		{
			while(j > -1 && s[i+1] != s[j+1]) j = next[j];
			if(s[i+1] == s[j+1]) ++j;
			next[i+1] = j;
		}
		if(len % (len - 1 - next[len-1]) == 0) printf("%d\n", len / (len - 1 - next[len-1]));
		else printf("1\n");
	}
	return 0;
}