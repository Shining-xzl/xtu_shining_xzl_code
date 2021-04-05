#include <cstdio>
#include <cstring>
using namespace std;
const int lim = 1030;
bool k[lim][lim];
int cnt[lim];
int s[lim],n;
int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&s[i]);
		}
		memset(k,0,sizeof(k));
		memset(cnt,0,sizeof(cnt));
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				int x = s[i] ^ s[j];
				if(k[x][s[i]] == 0)
					cnt[x]++,k[x][s[i]] = 1;
				if(k[x][s[j]] == 0)
					cnt[x]++,k[x][s[j]] = 1;
			}
		}
		int ans = -1;
		for(int i=1;i<=1024;i++)
		{
			if(cnt[i] == n)
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}