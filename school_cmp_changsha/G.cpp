#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int lim = 1e5+3;
map<int,vector<LL> > mp;
LL sum[lim];
int n,k,z;

int main()
{
	scanf("%d %d %d", &n,&k,&z);
	int kp;
	LL ans = 0;
	LL stand;
	if(z%k == 0) stand = z;
	else stand = (z/k + 1) * k;
	mp[0] = vector<LL>(1,0);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld", &sum[i]);
		sum[i] += sum[i-1];
		kp = sum[i] % k;
		if(mp.count(kp) == 0)
			mp[kp] = vector<LL>(0);
		mp[kp].push_back(sum[i]);
		int p = lower_bound(mp[kp].begin(),mp[kp].end(),sum[i] - (LL)stand) - mp[kp].begin();
		if(mp[kp][p] > sum[i] - (LL)stand) p--;
		ans += p + 1; 
	}
	printf("%lld\n",ans);
	return 0;
}
