#include <cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int LIM=50002;
int n,m;
int tree[LIM<<2];

void build(int id,int l,int r)
{
//	printf("%d %d %d\n",id,l,r);
	tree[id]=INF;
	if(l==r) return;
	int mid=l+r>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void updata(int id,int pos,int val,int l,int r)
{
	if(tree[id]>val) tree[id]=val;
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid)
		updata(id<<1,pos,val,l,mid);
	else updata(id<<1|1,pos,val,mid+1,r); 
}

int Min(int a,int b)
{
	return a<b?a:b;
}

int query(int id,int xl,int xr,int l,int r)
{
	if(xl<=l&&xr>=r) return tree[id];
	int mid=l+r>>1;
	if(mid>=xr) return query(id<<1,xl,xr,l,mid);
	else if(mid<xl) return query(id<<1|1,xl,xr,mid+1,r);
	else return Min(query(id<<1,xl,xr,l,mid),query(id<<1|1,xl,xr,mid+1,r));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int time,a,b,x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		updata(1,1,0,1,n);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			x=query(1,a,b,1,n);
			updata(1,b,x+1,1,n);
		}
		printf("%d\n",query(1,n,n,1,n));
		if(time) printf("\n");
	}
	return 0;
} 
