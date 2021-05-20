#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull f[70][70][103];
int n,k;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,Case = 0;
	scanf("%d", &T);
	while(T--)
	{
		memset(f, 0, sizeof(f));
		scanf("%d %d", &n,&k);
		printf("Case %d: ", ++Case);
		if(n & 1 || k == 0) printf("0\n");
		else
		{
			f[1][1][1%k] = 1;
			for (int i = 1; i < n; ++i)
			{
				for (int j = 0; j <= i; ++j)
				{
					f[i+1][j][0] += f[i][j][0];
					f[i+1][j+1][1%k] += f[i][j][0];
					for (int m = 1; m < k; ++m)
					{
						f[i+1][j][m*2%k] += f[i][j][m];
						f[i+1][j+1][(m*2+1)%k] += f[i][j][m];
					}
				}
			}
			printf("%lld\n", f[n][n/2][0]);
		}
	}
	return 0;
} 
