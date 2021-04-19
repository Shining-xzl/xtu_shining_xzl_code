#include <cstdio>
#include <map>
#include <vector>
using namespace std;
typedef unsigned long long LL;
typedef pair<int,int> Pr;
const LL NO = 1e18;
map<Pr,int> library;
vector<int> fibonacci;
LL a,b;
int n;

LL fast_pow(LL a,LL b,LL mod)
{
	if(b == 1) return a%mod;
	else if(b == 0) return 1;
	LL res = fast_pow(a,b/2,mod);
	res = res * res % mod;
	if(b&1LL) res = res * (a%mod) % mod;
	return res;
}

LL check(int s_pre)
{
	LL res = 1LL;
	if(a == 0 || n == 1) return 0;
	if(b == 0 || a == 1) return 1;
	for (LL i = 0; i < b; ++i)
	{
		res = res * a;
		if(res > (LL)s_pre) return NO;
	}
	return res;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T,num,now;
	Pr temp;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%llu %llu %d", &a,&b,&n);	
		library.clear();
		fibonacci.clear();
		fibonacci.push_back(0);
		fibonacci.push_back(1);
		num = 1;
		temp.first = 0;
		temp.second = 1;
		while(library.find(temp) == library.end())
		{
			library[temp] = num - 1;
			now = fibonacci[num] + fibonacci[num-1];
			if(now >= n) now -= n;
			fibonacci.push_back(now);
			++num;
			temp.first = temp.second;
			temp.second = fibonacci[num];
		}
		// printf("%d\n", library[temp]);
		int len = num - library[temp] - 1;
		// printf("%s\n", );
		int s_pre = library[temp];
		// printf("%d \n", len);
		LL pos = check(s_pre);
		if(pos == NO)
		{
			pos = fast_pow(a,b,(LL)len) - s_pre % len;
			pos = (pos + len) % len;
			if(pos == 0) pos = len;
			pos += s_pre;
			printf("%d\n", fibonacci[pos]);
		}
		else printf("%d\n", fibonacci[pos]);
	}
	
	return 0;
} 
