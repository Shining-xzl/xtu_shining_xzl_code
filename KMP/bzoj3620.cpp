#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 15004;

char s[lim];
int next[lim];
int k,ans = 0;
int num[lim];

#define Min(x,y) ((x)<(y)?(x):(y))

void get_next(char *s)
{

	int j,len = strlen(s);
	j = next[0] = -1;
	num[0] = lim;
	for (int i = 0; i < len-1; ++i)
	{
		while(j != -1 && s[i+1] != s[j+1]) j = next[j];
		if(s[i+1] == s[j+1]) ++j;
		next[i+1] = j;
		if(j < k - 1) num[i+1] = lim;
		else num[i+1] = Min(j,num[j]);
	} 
	for (int i = 0; i < len; ++i)
		if(num[i] * 2 + 1< i) ++ans;
}

int main()
{
	scanf("%s %d", s,&k);
	for (int i = 0; s[i] != 0; ++i)
		get_next(s+i);
	printf("%d\n", ans);
	return 0;
}