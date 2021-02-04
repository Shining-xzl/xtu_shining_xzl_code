# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
 
const int N=50005;
const int INF=1000000000;
 
int n,m;
int tr[N*4];
 
void build(int rt,int l,int r)
{
    tr[rt]=INF;
    if(l==r) return ;
    build(rt<<1,l,(l+r)/2);
    build(rt<<1|1,(l+r)/2+1,r);
}
 
void update(int pos,int rt,int val,int l,int r)
{
    if(tr[rt]>val) tr[rt]=val;
    if(l==r) return ;
    int m=(l+r)>>1;
    if(pos<=m) update(pos,rt<<1,val,l,m);
    else update(pos,rt<<1|1,val,m+1,r);
}
 
int query(int rt,int L,int R,int l,int r)
{
    if(L<=l&&r<=R) return tr[rt];
    int m=(l+r)>>1;
    if(R<=m) return query(rt<<1,L,R,l,m);
    else if(L>m) return query(rt<<1|1,L,R,m+1,r);
    else return min(query(rt<<1,L,R,l,m),query(rt<<1|1,L,R,m+1,r));
}
 
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
    int a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        update(1,1,0,1,n);
        while(m--){
            scanf("%d%d",&a,&b);
            int x=query(1,a,b,1,n);
            update(b,1,x+1,1,n);
        }
        printf("%d\n",query(1,n,n,1,n));
        if(T) printf("\n");
    }
    return 0;
}
