/*
无向图，度的和为偶数
奇数度出现是次数为偶数
*/
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
int N,E,T;
const int lim = 1003;

int degree[lim];
int father[lim];
bool vis[lim];
map<int,int> p;

void initail()
{
	p.clear();
	memset(vis, 0, sizeof(vis));
	memset(degree, 0, sizeof(degree));
	for (int i = 1; i <= N; ++i)
		father[i] = i;
}

int get_fa(int x)
{
	if (father[x] == x) return x;
	else return father[x] = get_fa(father[x]);
}

void add(int a,int b)
{
	int fa = get_fa(a),fb = get_fa(b);
	if(fa != fb)
		father[fa] = fb;
}

int main()
{
	int a,b,Case = 0;
	map<int,int>::iterator it;
	while(scanf("%d %d %d",&N,&E,&T) == 3 && N)
	{
		initail();
		for (int i = 0; i < E; ++i)
		{
			scanf("%d %d",&a,&b);
			add(a,b);
			++degree[a];
			++degree[b];
			vis[a] = 1;
			vis[b] = 1;
		}
		for (int i = 1; i <= N; ++i)
			if(vis[i])
			{
				a = get_fa(i);
				if(p.find(a) == p.end()) p[a] = 0;
				if(degree[i] & 1)
					++p[a];
			}
		int ans = E;
		for (it = p.begin(); it != p.end(); ++it)
		{
			if(it->second <= 2) continue;
			ans += (it->second-2)/2;
		}
		ans += p.size() - 1;
		if(ans < 0) ans = 0;
		printf("Case %d: %d\n", ++Case,ans * T);
	}
	return 0;
} 
