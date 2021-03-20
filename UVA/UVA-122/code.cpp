#include <cstdio>
using namespace std;

struct node
{
	int val;
	node *Lson,*Rson;
	node():val(-1),Lson(NULL),Rson(NULL) {}
};
node *head=new node();
bool flag=1;
void clear(node *x)
{
	if(x==NULL) return;
	clear(x->Lson);
	clear(x->Rson);
	delete x;
}

void print()
{
	int ans[300],l=1,r=1;
	node *q[300];
	q[1]=head;
	while(l<=r)
	{
		ans[l]=q[l]->val;
		if(ans[l]==-1) flag=0;
		if(q[l]->Lson!=NULL) q[++r]=q[l]->Lson;
		if(q[l]->Rson!=NULL) q[++r]=q[l]->Rson;
		l++;
	}
	if(flag)
	{
		for(int i=1;i<r;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[r]);
	}
	else printf("not complete\n");
}

void process(char *s)
{
	int op=1,x=0;
	node *now=head;
	while(s[op]!=',')
	{
		x=x*10+(s[op]^48);
		op++;
	}
	op++;
	while(s[op]!=')')
	{
		if(s[op]=='L')
		{
			if(now->Lson==NULL)
				now->Lson=new node();
			now=now->Lson;
		}
		else
		{
			if(now->Rson==NULL)
				now->Rson=new node();
			now=now->Rson;
		}
		op++;
	}
	if(now->val!=-1) flag=0;
	now->val=x;
}

int main()
{
	char s[30];
	while(scanf("%s",s)==1)
	{
		if(s[0]=='('&&s[1]==')')
		{
			print();
			clear(head);
			head=new node();
			flag=1;
			continue;
		}
		process(s);
	}
	return 0;
} 
