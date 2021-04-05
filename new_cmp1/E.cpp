#include <cstdio>

using namespace std;
const int lim = 1e6+2;
char stack[lim];
char s[lim];
int len = 0;

bool check(char c)
{
	if(c == '{' || c == '<' || c == '(' || c == '[')
		return 1;
	else return 0;
}

bool ok(char a,char b)
{
	if(a == '{' && b == '}')
		return 1;
	if(a == '<' && b == '>')
		return 1;
	if(a == '(' && b == ')')
		return 1;
	if(a == '[' && b == ']')
		return 1;
	return 0;
}

int main()
{
	int ans = 0;
	char c;
	scanf("%s",s);
	for (int i = 0; s[i] != 0; ++i)
	{
		c = s[i];
		if(check(c))
			stack[++len] = c;
		else if(len == 0)
		{
			printf("Impossible\n");
			return 0;
		}
		else
		{
			if(!ok(stack[len],c))
				++ans;
			--len;
		}
	}
	if(len)
		printf("Impossible\n");
	else printf("%d\n", ans);
	return 0;
}