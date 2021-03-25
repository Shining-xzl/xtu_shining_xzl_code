#include <cstdio>
#include <cstring>
using namespace std;
int in_degree[30],out_degree[30];
int n;
char sample[1003];

int father[30];

int get_fa(int x)
{
	if(father[x] == x) return x;
	else return father[x] = get_fa(father[x]);
}

void add(int a,int b)
{
	a = get_fa(a);
	b = get_fa(b);
	if(a != b)
		father[a]=b;
}

bool check()
{
	int Ofa = -1,fa;
	int numin = 0,numout = 0;
	for(int i = 0; i < 26; ++i)
		if(in_degree[i] + out_degree[i])
		{
			if(Ofa == -1) Ofa = get_fa(i);
			fa = get_fa(i);
			if(Ofa != fa) return false;
			if(in_degree[i] > out_degree[i])
			{
				if(in_degree[i] - out_degree[i] > 1)
					return false;
				numin++;
			}
			else if(out_degree[i] > in_degree[i])
			{
				if(out_degree[i] - in_degree[i] > 1)
					return false;
				numout++;
			}
		}
	if(numin > 1 || numout > 1 || numin != numout)
		return false;
	return true;
}

int main()
{
	int time,len;
	int start,end;
	scanf("%d", &time);
	while(time--)
	{
		scanf("%d ",&n);
		memset(in_degree, 0, sizeof(in_degree));
		memset(out_degree, 0, sizeof(out_degree));
		for(int i = 0; i < 27; ++i)
			father[i] = i;
		while(n--)
		{
			scanf("%s",sample);
			len = strlen(sample);
			start = sample[0] - 'a';
			end = sample[len-1] - 'a';
			add(start,end);
			out_degree[start]++;
			in_degree[end]++;
		}
		if(check()) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
} 
