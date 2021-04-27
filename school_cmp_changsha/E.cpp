#include <cstdio>

using namespace std;
const int lim = 1e6+5;

bool not_prime[lim];
int prime[80000],len = 0;

void get_prime()
{
	not_prime[0] = not_prime[1] = 1;
	for (int i = 2; i < lim; ++i)
	{
		if (!not_prime[i])
			prime[len++] = i;
		for (int j = 0; j < len && i * prime[j] < lim; ++j)
		{
			not_prime[i * prime[j]] = 1;
			if (i%prime[j] == 0)
				break;
		}
	} 
//	printf("%d\n",len);
}
char s[lim];
int S,c,u;

int main()
{
	get_prime();
	scanf("%s",s);
	for (int i = 0; s[i] != 0; ++i)
	{
		if(!not_prime[i+1])
		{
			if(s[i] == 'C') ++c;
			else if(s[i] == 'S') ++S;
			else if(s[i] == 'U') ++u;
		}
	}	
	if(c > 1 && S > 0 && u > 0)
		printf("Yes");
	else printf("No");
	return 0;
}
