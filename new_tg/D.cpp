#include <cstdio>

using namespace std;
const int lim = 2e6+3;
char s[lim];
int n,k;

char find(int p)
{
	while(p < n && s[p] == '?') p += k;
	if(s[p] == '1') return '1';
	if(s[p] == '0') return '0';
	return '?';
}

bool check()
{
	char c;
	int pos;
	int num1,num0;
	num1 = num0 = 0;
	for (int i = 0; i < k; ++i)
	{
		pos = i;
		c = find(i);
		if(c == '1') ++num1;
		if(c == '0') ++num0;
		while(pos < n) 
		{
			if(s[pos] == '?') s[pos] = c;
			if(s[pos] != c) return 0;
			pos += k;
		}
	}
	if(num1 > k/2 || num0 > k/2) return 0;
	else return 1;
}

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	if(k&1) printf("No\n");
	else if(check()) printf("Yes\n");
	else printf("No\n");
	return 0;
}