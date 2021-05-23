#include <cstdio>
#include <algorithm>

using namespace std;

struct work
{
	int B,L;
 	bool operator < (const work &x) const 
	{
		return L > x.L;
	}
}s[1003];
int N;
#define Max(x,y) ((x)>(y)?(x):(y))

int main()
{
	// freopen("in.txt","r",stdin);
	int Case = 0;
	while(scanf("%d",&N) == 1 && N)
	{
		for (int i = 0; i < N; ++i)
			scanf("%d %d", &s[i].B,&s[i].L);
		sort(s,s+N);
		int ans = 0, sum = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += s[i].B;
			ans = Max(ans,sum + s[i].L);
		}
		printf("Case %d: %d\n", ++Case,ans);
	}
	return 0;
}