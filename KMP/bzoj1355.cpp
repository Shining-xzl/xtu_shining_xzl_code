#include <cstdio>
using namespace std;
const int lim = 1e6+3;
char s[lim];
int next[lim],len;
int main()
{
	scanf("%d", &len);
	scanf("%s", s);
	int j = -1;
	next[0] = -1;
	for (int i = 0; i < len-1; ++i)
	{
		while(j > -1 && s[j+1] != s[i+1]) j = next[j];
		if(s[j+1] == s[i+1]) ++j;
		next[i+1] = j;
	}
	int ans = len - 1 - next[len-1];
	printf("%d\n", ans);
	return 0;
}