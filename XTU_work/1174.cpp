#include <cstdio>

using namespace std;

int ans[100003];
#define Min(x,y) ((x)<(y)?(x):(y))

int read()
{
	char c = getchar();
	int res = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

char reads()
{
	char c = getchar();
	char s[10],len = 0;
	while (c < 'A' || c > 'Z') c = getchar();
	while(c >= 'A' && c <= 'Z')
	{
		s[len++] = c;
		c = getchar(); 
	}
	return s[1];
}

void work()
{
	char s;
	ans[0] = 2e9;
	int n,len = 0;
	scanf("%d", &n);
	while(n--)
	{
		s = reads();
		if (s == 'U')
		{
			ans[++len] = read();
			ans[len] = Min(ans[len],ans[len-1]);	
		}
		else if (s == 'I')
		{
			if (len == 0) printf("NULL\n");
			else printf("%d\n",ans[len]);
		}
		else if (s == 'O' && len > 0) len--;	
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) work();
	return 0;
}