#include <cstdio>
using namespace std;

int main()
{
	// freopen("in.txt","r",stdin);
	bool x=0;
	char c=getchar();
	while(c!=EOF)
	{
		if(c=='\"')
		{
			if(x) printf("''");
			else printf("``");
			x^=1;
		}
		else putchar(c);
		c=getchar();
	}	
	return 0;
}