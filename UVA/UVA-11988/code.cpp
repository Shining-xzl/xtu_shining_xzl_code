#include <cstdio>
using namespace std;
struct node
{
	node *next;
	char val;
}head;
char s[100003];

void initail(node *x)
{
	if(x==NULL) return;
	initail(x->next);
	delete x;
}

void process()
{
	node *op,*tag,*temp;
	tag=op=&head;
	for(int i=0;s[i]!=0;i++)
	{
		if(s[i]=='[')
			op=&head;
		else if(s[i]==']')
			op=tag;
		else
		{
			temp=new node;
			temp->val=s[i];
			temp->next=op->next;
			op->next=temp;
			if(tag==op) tag=temp;
			op=temp;
		}
	}
	for(op=head.next;op!=NULL;op=op->next)
		printf("%c",op->val);
	printf("\n");
}

int main()
{
	// freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	head.next=NULL;
	while(gets(s))
	{
		initail(head.next);
		head.next=NULL;
		process();
	}
	return 0;
} 
