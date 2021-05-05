#include <cstdio>
#include <cstring>
using namespace std;
int n,k;

double rate[23];
double sum[23],tot;

void solve(int now,int k,int num,double rl)
{
	if(now >= n)
	{
		tot += rl;
		for (int i = 0; i < n; ++i)
			if (k&(1<<i))
				sum[i] += rl;
		return;
	}
	if(num > 0)
		solve(now+1,k|(1<<now),num-1,rl*rate[now]);
	if(n - now > num)
		solve(now+1,k,num,rl*(1-rate[now]));
}

int main()
{
	int Case = 0;
	while(scanf("%d %d",&n,&k) == 2)
	{
		if (n == 0 && k == 0) break;
		for (int i = 0; i < n; ++i)
			scanf("%lf", &rate[i]);
		tot = 0;
		memset(sum, 0, sizeof(sum));
		solve(0,0,k,1);
		printf("Case %d:\n", ++Case);
		for (int i = 0; i < n; ++i)
			printf("%.6f\n", sum[i]/tot);
	}
	return 0;
} 
