#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 1004;
int next[lim];
char s[lim];
char t[lim];
int ans;

void get_next()
{
	int len = strlen(t),j = -1,i = 0;
	next[0] = -1;
	while(i < len - 1) // next[i] 对应上一个 不相等的 s[i]
	{
		if(j == -1 || s[i] == s[j])
		{
			++i; ++j;
			if(s[i] == s[j])
				next[i] = next[j];
			else next[i] = j;
		}
		else j = next[j];
	}
/*
	for (int i = 0; i < len; ++i) // next[i] 对应上一个 相等的 s[i]
	{
		while(j > -1 && s[i+1] != s[j+1]) j = next[j];
		if(s[i+1] == s[j+1]) ++j;
		next[i+1] = j;
	}
*/
}

int KMP()
{
	int res = 0, lens = strlen(s), lent = strlen(t);
	int i = 0, j = 0;
	while(i < lent)
	{
		while(j != -1 && t[i] != s[j]) j = next[j];
		++j; ++i;
		if(j == lens)
		{
			j = 0;
			++res;
		}
	}
	return res;

}

int main()
{
	while(scanf("%s", t) == 1)
	{
		if(t[0] == '#') break;
		scanf("%s", s);
		get_next();
		int ans = KMP();
		printf("%d\n",ans);
	}
	return 0;
}