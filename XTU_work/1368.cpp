#include <cstdio>
#include <cstring>
using namespace std;

int num[30];
char s[2003];
#define Min(x,y) ((x)<(y)?(x):(y))
int main()
{
	int count;
	int ans,l;
	while(scanf("%s", s) == 1)
	{
		memset(num, 0, sizeof(num));
		ans = 1e9;
		l = 0;
		count = 0;
		for (int  i = 0; s[i] != 0; ++i)
		{
			if(num[s[i] - 'a'] == 0) ++count;
			++num[s[i] - 'a'];
			while(count == 26)
			{
				ans = Min(ans,i-l+1);
				--num[s[l] - 'a'];
				if (num[s[l] - 'a'] == 0) --count;
				++l;
			}
		}
		printf("%d\n",ans < 3000 ? ans : 0);
	}
	return 0;
}