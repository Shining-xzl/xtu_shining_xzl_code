#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int indegree[60];
int link[60][60];
int n;

void clear_all()
{
	memset(link, 0, sizeof(link));
	memset(indegree, 0, sizeof(indegree));
}

void add(int a,int b)
{
	if(b == -1) return;
	if(link[a][b] == 0)
		indegree[b]++;
	link[a][b] = 1;
}

int reget(int x)
{
	if(x < 26) return x + 26;
	else return x - 26;
}

void get_link(int a,int b,int c,int d)
{
	int x;
	if(a != -1)
	{
		x = reget(a);
		add(x,b);
		add(x,c);
		add(x,d);
	}
	if(b != -1)
	{
		x = reget(b);
		add(x,a);
		add(x,c);
		add(x,d);
	}
	if(c != -1)
	{
		x = reget(c);
		add(x,a);
		add(x,b);
		add(x,d);
	}
	if(d != -1)
	{
		x = reget(d);
		add(x,a);
		add(x,b);
		add(x,c);
	}
}

void process(int &x,char a,char b)
{
	if(a == '0') x = -1;
	else
	{
		x = a - 'A';
		if(b == '+') x = x + 26;
	}
	return;
}

bool check()
{
	int x;
	queue<int> q;
	for(int i = 0; i < 52; ++i)
		if(indegree[i] == 0)
			q.push(i);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(int i = 0; i < 52; ++i)
			if(link[x][i] == 1)
			{
				--indegree[i];
				if(indegree[i] == 0)
					q.push(i);
			}
	}
	for(int i = 0; i < 52; ++i)
		if(indegree[i] > 0)
			return 1;
	return 0;
}

int main()
{
	char s[9];
	int a,b,c,d;
	while(scanf("%d", &n) == 1)
	{
		clear_all();
		while(n--)
		{
			scanf("%s", s);
			process(a,s[0],s[1]);	
			process(b,s[2],s[3]);
			process(c,s[4],s[5]);
			process(d,s[6],s[7]);
			get_link(a,b,c,d);
		}
		if(check()) printf("unbounded\n");
		else printf("bounded\n");
	}
	return 0;
} 
