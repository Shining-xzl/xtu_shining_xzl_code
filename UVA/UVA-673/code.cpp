#include <cstdio>
#include <stack>
using namespace std;
stack< char > p;
char s[129];

bool check()
{
	for(int i = 0; s[i] != 0; ++i)
	{
		if(s[i] == '(' || s[i] == '[')
			p.push(s[i]);
		else if(s[i] == ')')
		{
			if(p.empty() || p.top() != '(') return 0;
			else p.pop();
		}
		else if(s[i] == ']')
		{
			if(p.empty() || p.top() != '[') return 0;
			else p.pop();
		}
	}
	return p.empty();
}

int main()
{
	int n;
	scanf("%d", &n);
	gets(s);
	while(n--)
	{
		while(!p.empty()) p.pop();
		gets(s);
		if(check()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
