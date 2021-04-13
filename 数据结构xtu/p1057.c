#include <stdio.h>

int main()
{
	char s[257];
	char stack[257];
	int i,len = 0;
	scanf("%s",&s);
	for (i = 0; s[i] != 0; ++i)
	{
		if(s[i] == '(' || s[i] == '[')
			stack[++len] = s[i];
		else 
		{
			if(len == 0)
			{
				printf("Wrong\n");
				return 0;
			}
			if(s[i] == ')' && stack[len] == '(')
				--len;
			else if(s[i] == ']' && stack[len] == '[')
				--len;
			else
			{
				printf("Wrong\n");
				return 0;
			}
		}
	}
	if(len == 0) printf("OK\n");
	else printf("Wrong\n");
	return 0;
}