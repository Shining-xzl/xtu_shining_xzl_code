#include <stdio.h>
#include <string.h>

int main()
{
	char s[34];
	scanf("%s", s);
	int len = strlen(s);
	if(len > 3 && s[len-1] == 'g' && s[len-2] == 'n' && s[len-3] == 'i')
		s[len - 3] = 0;
	if(len > 2 && s[len-1] == 'r' && s[len-2] == 'e')
		s[len - 2] = 0;
	if(len > 2 && s[len-1] == 'y' && s[len-2] == 'l')
		s[len - 2] = 0;
	printf("%s\n", s);
	return 0;
}