#include <cstdio>
#include <cstring>
using namespace std;
const int sta = 1953125;
int a;
double rate[sta+3];
bool vis[sta+3];
int f[10][6];

int _code(int *x)
{
	int res = 0;
	for (int i = 8; i >= 0; --i)
		res = res * 5 + x[i];
	return res;
}

void dfs(int now)
{
	if(vis[now] || now == 0) return;
	vis[now] = 1;
	int k[10],p = now;
	for (int i = 0; i < 9; ++i)
	{
		k[i] = p % 5;
		p /= 5;
	}
	int temp,count = 0;
	for (int i = 0; i < 9; ++i)
	{
		if(k[i] == 0) continue;
		for (int j = i+1; j < 9; ++j)	
		{
			if(k[j] == 0) continue;
			if(f[i][k[i]] == f[j][k[j]])
			{
				++count;
				--k[i]; --k[j];
				temp = _code(k);
				dfs(temp);
				rate[now] += rate[temp];
				++k[i]; ++k[j];
			}
		}
	}
	if(count > 0)
		rate[now] /= count;
}

int main()
{
	char s[3];
	while(scanf("%s",s) == 1)
	{
		f[0][1] = s[0];
		for (int j = 2; j <= 4; ++j)
			{
				scanf("%s",s);
				f[0][j] = s[0];
			}
		for (int i = 1; i < 9; ++i)
			for (int j = 1; j <= 4; ++j)
			{
				scanf("%s",s);
				f[i][j] = s[0];
			}
		memset(rate, 0, sizeof(rate));
		memset(vis, 0, sizeof(vis));
		rate[0] = 1.0;
		vis[0] = 1;
		dfs(sta-1);
		printf("%f\n",rate[sta-1]);		
	}
	return 0;
} 
