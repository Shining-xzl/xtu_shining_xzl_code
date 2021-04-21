/*
组合数素数分解；
判断整除关系
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned int Ut;
typedef unsigned long long UL;
const Ut lim = 1e5+3;
Ut not_prime[lim];
Ut prime[9600],len = 0;
Ut n,m;
Ut num[9600];
vector< pair<Ut,Ut> > match;
Ut ans[lim],xlen;

void get_prime()
{
	for (Ut i = 2; i < lim; ++i)
	{
		if(!not_prime[i])
			prime[len] = i,not_prime[i] = len++;
		for (Ut j = 0; j < len && i*prime[j] < lim; ++j)
		{
			not_prime[i*prime[j]] = -1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

void full(Ut x,Ut offset)
{
	Ut i = 0;
	while(prime[i] * prime[i] <= x)
	{
		while(x%prime[i] == 0)
		{
			num[i] += offset;
			x/=prime[i];
		}
		i++;
	}
	if(x > 1)
		num[not_prime[x]] += offset;
}

bool check()
{
	Ut len = match.size();
	for (Ut i = 0; i < len; ++i)
	{
		if(num[match[i].first] < match[i].second)
		{
			return false;
		}	
	}
	return true;
}

void print(Ut a)
{
	char s[20],len = 0;
	do
	{
		s[len++] = a % 10 + '0';
		a /= 10;
	}while(a>0);
	while(len--) putchar(s[len]);
}

void solve()
{
	memset(num, 0, sizeof(num));
	match.clear();
	pair<Ut,Ut> temp;
	for (Ut i = 0; i < len; ++i)
	{
		if(m == 1) break;
		if(m % prime[i] == 0)
		{
			temp.first = i;
			temp.second = 0;
			while(m % prime[i] == 0)
			{
				++temp.second;
				m /= prime[i];
			}
			match.push_back(temp);
		}
	}
	if(match.size() == 0 || m > 1)
	{
		printf("0\n\n");
		return;
	}
	xlen = 0;
	for (Ut i = 1; i < n; ++i)
	{
		full(n-i+1,1);
		full(i,-1);
		if(check())
			ans[xlen++] = i+1;
	}
	printf("%u\n", xlen);
	for (Ut i = 0; i < xlen; ++i)
	{
		if(i) putchar(' ');
		print(ans[i]);	
	}
	printf("\n");
}

int main()
{
	get_prime();
	while(scanf("%u %u", &n,&m) == 2)
	{
		--n;
		solve();
	}
	return 0;
} 
