//题意不清，SB一样
#include <cstdio>
#include <cstring>
using namespace std;
char map[203][203];
int n;
void down(int id,int pos);

void build(int id, int l,int r)
{
	if(id >= n) return;
	int len = strlen(map[id]);
	if(r > len) r = len;
	for(int i = l; i < r; ++i)
	{
		if(map[id][i] != ' ' && 
		   map[id][i] != '-' &&
		   map[id][i] != '|')
		{
			putchar(map[id][i]);
			putchar('(');
			down(id+2, i);
			putchar(')');
		}
	}
}

void down(int id,int pos)
{
	if(map[id-1][pos] == ' ') return;
	if(id >= n) return;
	int l = pos,r = pos, len = strlen(map[id])-1;
	while(l > 0 && map[id][l-1] == '-') --l;
	while(r < len && map[id][r+1] == '-') ++r;
	build(id+1, l, r+1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int time;
	scanf("%d", &time);
	gets(map[0]);
	while(time--)
	{
		n = 0;
		memset(map, 0, sizeof(map));
		while(gets(map[n]))
		{
			if(!strcmp("#",map[n])) break;
			n++;
		}
		putchar('(');
		build(0, 0, strlen(map[0]));
		putchar(')');
		putchar('\n');
	}
	return 0;
} 
