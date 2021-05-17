#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;

typedef vector<char> VC;
VC f[10003];

void puls(VC &a,VC &b,VC &c)
{
	int len1,len2;
	c.clear();
	if (a.size() > b.size()) len1 = a.size(), len2 = b.size();
	else len2 = a.size(), len1 = b.size();
	for (int i = 0; i < len2; ++i)
		c.push_back(a[i] + b[i]);
	for (int i = len2; i < len1; ++i)
	{
		if(a.size() > b.size())
			c.push_back(a[i]);
		else c.push_back(b[i]);
	}
	for (int i = 0; i < len1 - 1; ++i)
	{
		if(c[i] > 9)
		{
			c[i] -= 10;
			c[i+1] += 1;
		}
	}
	if(c[len1-1] > 9)
	{
		c[len1-1] -= 10;
		c.push_back(1);
	}
}

void print(const VC &s)
{
	int len = s.size();
	for (int i = len-1; i >= 0; --i)
		putchar(s[i] + '0');
	putchar('\n');
}

int main()
{
	f[0].push_back(1);
	f[1].push_back(1);
	for (int i = 2; i < 10003; ++i)
		puls(f[i-2],f[i-1],f[i]); 
	int n;
	VC temp;
	while(scanf("%d", &n) == 1)
	{
		puls(f[n],f[n-2],temp);
		print(temp);
	}
	return 0;
} 
