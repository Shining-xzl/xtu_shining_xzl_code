#include <cstdio>
#include <cstring>
using namespace std;
char s[103];

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int len,a,b;
	while(scanf("%s",s) == 1)
	{
		len = strlen(s);
		s[len] = s[0];
		a = b = 0;
		for (int i = 0; i < len; ++i)
		{
			if(s[i] == '0') ++b;
			if(s[i] == s[i+1] && s[i] == '0') ++a;
		}
		if (a * len > b * b) printf("SHOOT\n");
		else if (a * len < b * b) printf("ROTATE\n");
		else printf("EQUAL\n");
	}
	return 0;
} 
