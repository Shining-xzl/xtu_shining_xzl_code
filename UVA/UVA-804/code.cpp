#include <cstdio>
#include <vector>

using namespace std;
int num[102];
vector< int > f[102];
int NP,NT,NF,now;

void initail()
{
	for (int i = 0; i < 102; ++i)
		f[i].clear();
}

void show()
{
	printf("Places with tokens:");
	for (int i = 1; i <= NP; ++i)
	{
		if(num[i] > 0)
			printf(" %d (%d)", i,num[i]);
	}
	printf("\n");
}

bool work()
{
	for (int i = 0; i < NT; ++i)
	{
		int j = 0,len = f[i].size(),pos;
		while(j < len)
		{
			pos = f[i][j];
			if(pos > 0) ++num[pos];
			else if(pos < 0 && num[-pos] > 0) --num[-pos];
			else break;
			++j;
		}
		if(j == len) return 1;
		--j;
		while(j >= 0)
		{
			pos = f[i][j];
			if(pos > 0) --num[pos];
			else if(pos < 0) ++num[-pos];
			--j;
		}
	}
	return 0;
}

int main()
{
	int x,Case = 0;
	while(scanf("%d",&NP) == 1 && NP)
	{
		initail();
		for (int i = 1; i <= NP; ++i)
			scanf("%d",&num[i]);
		scanf("%d",&NT);
		for (int i = 0; i < NT; ++i)
		{
			while(scanf("%d",&x) == 1 && x)
				f[i].push_back(x);	
		}
		scanf("%d",&NF);
		now = 0;
		while(now < NF && work()) ++now;
		printf("Case %d:", ++Case);
		if(now < NF) printf(" dead after %d transitions\n", now);
		else printf(" still live after %d transitions\n", NF);
		show();
		printf("\n");
	}
	return 0;
} 
