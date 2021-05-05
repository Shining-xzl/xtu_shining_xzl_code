#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char s[6][6],p[6][6];

void init()
{
	scanf("%d", &n);
	--n;
	for (int i = 0; i < 6; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < 6; ++i)
		scanf("%s", p[i]);
}

bool xfind(char c,int col)
{
	for (int i = 0; i < 6; ++i)
		if (p[i][col] == c) return 1;
	return 0;
}

void solve()
{
	vector<char> l[5];
	vector<int> pos(5);
	vector<int> k(5);
	vector<char>::iterator it;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 6; ++j)
			if (xfind(s[j][i],i))
				l[i].push_back(s[j][i]);
	for (int i = 4; i >= 0; --i)
	{
		sort(l[i].begin(),l[i].end());
		it = unique(l[i].begin(),l[i].end());
		l[i].erase(it,l[i].end());
		// printf("%d : %d\n",i,l[i].size());
		if(i == 4) k[i] = 1;
		else k[i] = k[i+1] * l[i+1].size();
		if(l[i].size() == 0) k[i] = 0;
	}
	if(k[0] == 0)
	{
		printf("NO\n");
		return;
	}
	for (int i = 0; i < 5; ++i)
	{
		pos[i] = n/k[i];
		n %= k[i];
		if(pos[i] >= l[i].size())
		{
			printf("NO\n");
			return;
		}
	}
	for (int i = 0; i < 5; ++i)
		printf("%c", l[i][pos[i]]);
	printf("\n");
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		solve();
	}
	return 0;
} 
