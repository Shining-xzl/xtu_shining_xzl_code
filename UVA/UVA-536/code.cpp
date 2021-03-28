#include <cstdio>
#include <cstring>
using namespace std;
char s[30],p[30];
int pos[30],len,now;

struct tree
{
	char val;
	tree *Lson,*Rson;
	tree() : val(0),Lson(NULL),Rson(NULL) {}
};
tree *head;

void clear(tree *x)
{
	if(x == NULL) return;
	clear( x->Lson );
	clear( x->Rson );
	delete x;
}

void build(tree *x,int l,int r)
{
	int mid = pos[ s[now++] ];
	x->val = p[mid];
	if(l < mid) 
	{
		x->Lson = new tree();
		build(x->Lson,l,mid-1);
	}
	if(r > mid)
	{
		x->Rson = new tree();
		build(x->Rson,mid+1,r);
	}
}

void dfs(tree *x)
{
	if(x == NULL) return;
	dfs(x->Lson);
	dfs(x->Rson);
	printf("%c",x->val+'A');
}

int main()
{
	while(scanf("%s %s", s,p) == 2)
	{
		len = strlen(s);
		now = 0;
		head = new tree();
		for(int i = 0; p[i] != 0; ++i)
		{
			p[i] = p[i] - 'A';
			s[i] = s[i] - 'A';
			pos[p[i]] = i;
		}
		build(head,0,len-1);
		dfs(head);
		putchar('\n');
		clear(head);
	}
	return 0;
} 
