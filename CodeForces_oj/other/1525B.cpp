#include <cstdio>

using namespace std;
int s[103];
int n;

bool check()
{
	for (int i = 1; i <= n; ++i)
		if(s[i] != i) return 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &s[i]);
		if(check()) printf("0\n");
		else if(s[1] == n && s[n] == 1) printf("3\n");
		else if(s[1] == 1 || s[n] == n) printf("1\n");
		else printf("2\n");
	}
	return 0;
}