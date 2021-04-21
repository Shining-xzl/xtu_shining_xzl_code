#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q_min;
priority_queue<int,vector<int>,less<int> > q_max;
const int lim = 1e5+3;
int n;
long long sum1[lim],sum2[lim];
int sample[lim*3];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n*3; ++i)
		scanf("%d", &sample[i]);
	for (int i = 1; i <= n; ++i)
		sum1[0] += sample[i],q_min.push(sample[i]);
	for (int i = n*2+1; i <= n*3; ++i)
		sum2[n+1] += sample[i],q_max.push(sample[i]);
	int pos;
	for (int i = 1; i <= n; ++i)
	{
		pos = i + n;
		sum1[i] = sum1[i-1];
		if(sample[pos] > q_min.top())
		{
			sum1[i] += sample[pos] - q_min.top();
			q_min.pop();
			q_min.push(sample[pos]);
		}
	}
	for (int i = n; i >= 1; --i)
	{
		pos = i + n;
		sum2[i] = sum2[i+1];
		if(sample[pos] < q_max.top())
		{
			sum2[i] += sample[pos] - q_max.top();
			q_max.pop();
			q_max.push(sample[pos]);
		}
	}
	long long ans = -1e18;
	for (int i = 0; i <= n; ++i)
	{
		if(ans < sum1[i] - sum2[i+1])
			ans = sum1[i] - sum2[i+1];
	}
	printf("%lld\n", ans);
	return 0;
}