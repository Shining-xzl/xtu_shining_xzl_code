#include <cstdio>

using namespace std;
const int lim = (1 << 16) + 4;
const int Rf = (1 << 16) - 1;
const int Rp[] = {15,15<<4,15<<8,15<<12,4369,4369<<1,4369<<2,4369<<3,
				  51,51<<1,51<<2,51<<4,51<<5,51<<6,51<<8,51<<9,51<<10}; 
int ans[lim];
int q[lim];
#define Min(x,y) ((x)<(y)?(x):(y))

void prime()
{
	for (int i = 0; i < lim; ++i) ans[i] = 1e9;
	int l = 1, r = 1,t;
	q[1] = 0;
	ans[0] = 0;
	while(l <= r)
	{
		for (int i = 0; i < 17; ++i)
		{
			t = q[l] ^ Rp[i];
			if (ans[t] == 1e9)
			{
				ans[t] = ans[q[l]] + 1;
				q[++r] = t;
			}
		}
		l++;
	}
}

int read()
{
	int res = 0;
	char s[18];
	scanf("%s", s);
	for (int i = 0; i < 16; ++i)
		res = (res << 1) + (s[i] == '1' ? 1 : 0);	
	return res;
}

int main()
{
	prime();
	int T,a,p;
	scanf("%d", &T);
	while(T--)
	{
		a = read();
		p = Min(ans[a],ans[a^Rf]);
		printf("%d\n",p < 1e9 ? p : -1);
	}
	return 0;
}