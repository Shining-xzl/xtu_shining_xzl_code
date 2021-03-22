#include <cstdio>
using namespace std;
const int lim=4096+5;
struct treex
{
	int num;
	treex *LUson,*RUson,*LDson,*RDson;
	treex():num(0),LUson(NULL),RUson(NULL),LDson(NULL),RDson(NULL) {}
};

char s1[lim],s2[lim];
treex *head;

void clear(treex *x)
{
	if(x==NULL) return;
	clear(x->LUson);
	clear(x->RUson);
	clear(x->LDson);
	clear(x->RDson);
	delete x;
}
char *p;
void build(treex *x,int num)
{
	if(*p=='f')
	{
		x->num=num;
		return;
	}
	if(*p=='e') return;
	p++;
	if(x->LUson==NULL) x->LUson=new treex();
	build(x->LUson,num>>2);
	p++;
	if(x->RUson==NULL) x->RUson=new treex();
	build(x->RUson,num>>2);
	p++;
	if(x->LDson==NULL) x->LDson=new treex();
	build(x->LDson,num>>2);
	p++;
	if(x->RDson==NULL) x->RDson=new treex();
	build(x->RDson,num>>2);
	x->num=x->LUson->num+x->RUson->num+x->LDson->num+x->RDson->num;
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%s",s1,s2);
		head=new treex();
		p=&s1[0];
		build(head,1024);
		p=&s2[0];
		build(head,1024);
		printf("There are %d black pixels.\n",head->num);
		clear(head);
	}
	return 0;
} 
