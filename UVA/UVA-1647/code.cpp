/*
异或的规律，明显的对称性
*/

#include <cstdio>
#include <cstring>
using namespace std;

int f[2][2][400];
int ans[1003][400];

void puls(int a[],int b[],int c[])
{
	int lena = a[0];
	int lenb = b[0];
	int &len = c[0];
	if(lena > lenb) len = lena;
	else len = lenb;
	for (int i = 1; i <= len; ++i)
		c[i] = a[i] + b[i];
	for (int i = 1; i < len; ++i)
		if(c[i] > 9) 
		{
			c[i] -= 10;
			++c[i+1];
		}
	if(c[len] > 9) c[len] -= 10, c[++len] = 1;
}
int stand_1[400];

int main()
{
	int n;
	stand_1[0] = stand_1[1] = 1;
	int l,r;
	l = r = 0;
	int pre = 0, now = 1;
	memset(f,0,sizeof(f));
	f[now][0][0] = 1;
	f[now][1][0] = 1;
	for (int i = 1; i <= 1000; ++i)
	{
		pre ^= 1;
		now ^= 1;
		memset(f[now], 0, sizeof(f[now]));
		puls(f[pre][1],f[pre][0],f[now][1]);
		puls(f[pre][1],f[pre][0],f[now][0]);
		if(l == 1 && r == 0)
			puls(f[now][1],stand_1,f[now][0]);
		else if(l == 0 && r == 1)
			puls(f[now][0],stand_1,f[now][1]);
		r ^= 1;
		if(i & 1)
		{
			for (int j = 0; j < 400; ++j)
				ans[i][j] = f[now][0][j];
		}
	}
	l = r = 1;
	pre = 0, now = 1;
	memset(f,0,sizeof(f));
	f[now][0][0] = 1;
	f[now][1][0] = 1;
	for (int i = 1; i <= 1000; ++i)
	{
		pre ^= 1;
		now ^= 1;
		memset(f[now], 0, sizeof(f[now]));
		puls(f[pre][1],f[pre][0],f[now][1]);
		puls(f[pre][1],f[pre][0],f[now][0]);
		if(l == 1 && r == 0)
			puls(f[now][1],stand_1,f[now][0]);
		else if(l == 0 && r == 1)
			puls(f[now][0],stand_1,f[now][1]);
		r ^= 1;
		if((i & 1) == 0)
		{
			for (int j = 0; j < 400; ++j)
				ans[i][j] = f[now][0][j];
		}
	}
	ans[0][0] = 1;
	while(scanf("%d", &n) == 1)
	{
		for (int i = ans[n][0]; i > 0; i--)
			putchar(ans[n][i] + '0');
		putchar('\n');
	}
	return 0;
} 
