#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
const int lim=1e4+3;

int a[lim],b[lim],n;
int pos[lim],posx;

struct node
{
	int val;
	node *lson,*rson;
	node():val(0),lson(NULL),rson(NULL) {}
};
node *head;
void clear(node *x)
{
	if(x==NULL) return;
	clear(x->lson);clear(x->rson);
	delete x;
}

bool initail()
{
	stringstream POM;
	string s;
	n=0;
	int op=1;
	if(!getline(cin,s)) return 0;
	POM.clear();
	POM.str(s);
	while(POM>>a[op])
	{
		pos[a[op]]=op;
		n++;
		op++;
	}
	getline(cin,s);
	POM.clear();
	POM.str(s);
	for(op=1;op<=n;op++)
		POM>>b[op];
	return 1;
}

int ans,Sumx;

void build(node *now,int l,int r,int x,int sum)
{
	now->val = a[x];
	sum+=a[x];
	if(l==r)
	{
		if(sum<Sumx) ans=a[x],Sumx=sum;
		else if(sum==Sumx&&ans>a[x]) ans=a[x];
		return;
	}
	if(x<r)
	{	
		now->rson=new node();
		posx--;
		build(now->rson,x+1,r,pos[b[posx]],sum);
	}
	if(l<x)
	{
		now->lson=new node();
		posx--;
		build(now->lson,l,x-1,pos[b[posx]],sum);
	}
	
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(initail())
	{
		ans=Sumx=1e9;
		clear(head);
		head=new node();
		posx=n;
		build(head,1,n,pos[b[posx]],0);
		printf("%d\n",ans);
	}
	return 0;
} 
