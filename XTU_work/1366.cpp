#include <cstdio>
#include <algorithm>
using namespace std;
const int lim = 1e5+3;
int n,m;

struct cp
{
	int num,id;
	bool operator < (const cp &x) const
	{
		return num < x.num;
	}
};
cp s[lim << 1];

int read()
{
	int res = 0;
	char c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

#define Min(x,y) ((x)<(y)?(x):(y))

int main()
{
	int T,ans;
	scanf("%d", &T);
	while(T--)
	{
		n = read(); m = read();
		for (int i = 0; i < n; ++i)
			s[i].num = read(),s[i].id = 0;
		for (int i = 0; i < m; ++i)
			s[i+n].num = read(),s[i+n].id = 1;
		sort(s,s+n+m);
		ans = 1e9;
		for (int i = 1; i < n+m; ++i)
		{
			if (s[i].id != s[i-1].id)
			{
				ans = Min(s[i].num - s[i-1].num,ans);
			}
		}
		printf ("%d\n",ans);
	}
	return 0;
}