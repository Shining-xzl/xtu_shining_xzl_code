#include <cstdio>

using namespace std;
const int lim = 2e5+3;
typedef long long LL;

LL s[lim];
LL temp[lim],ans;
int K,N;

void resort(int l,int r)
{
	if(l == r) return;
	int mid = (l+r)>>1;
	resort(l,mid); resort(mid+1,r);
	int a = l, b = mid+1, op = l;
	while(a <= mid || b <= r)
	{
		if(a>mid)
			temp[op++] = s[b++];
		else if(b>r)
			temp[op++] = s[a++];
		else
		{
			if(s[a] > s[b]) 
				temp[op++] = s[a++];
			else
			{
				ans += (LL) (mid - a + 1);
				temp[op++] = s[b++];
			}
		}
	}
	for (int i = l; i <= r; ++i)
		s[i] = temp[i];
}

int main()
{
	scanf("%d %d", &N,&K);
	ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%lld", &s[i]);
		s[i] -= K;
		s[i] += s[i-1];
	}
	s[0] = 0;
	resort(0,N);
	printf("%lld\n", ans);
	return 0;
}