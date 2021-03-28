#include <cstdio>
using namespace std;
int n,m;
int pos[12];
char s[130];
bool f[9];

void pass_code(int id,int l,int r)
{
	if(l==r)
	{
		printf("%c", s[l]);
		return;
	}
	int mid = (l + r) >> 1;
	// printf("%d\n",f[id]);
	if(f[id]) pass_code(id+1,mid+1,r);
	else pass_code(id+1,l,mid);
}

int main()
{
	char v[8];
	int Case=0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; ++i)
		{
			scanf("%s", v);
			v[1]-='0';
			pos[(int)v[1]] = i;
		}
		scanf("%s", s+1);
		scanf("%d", &m);
		printf("S-Tree #%d:\n", ++Case);
		while(m--)
		{
			scanf("%s", v+1);
			for(int i = 1; v[i] != 0; ++i)
				f[pos[i]] = v[i] - '0';
			pass_code(1,1,1<<n);
		}
		printf("\n\n");
	}
	return 0;
} 
