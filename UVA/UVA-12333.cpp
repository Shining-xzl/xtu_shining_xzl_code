/*
边集数组
字典树
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int TNT=4000000;

struct tree
{
	int c;
	int son,next,num;
}s[TNT+3];
int head[TNT+3],op=0;
int a[103],b[103];

void build(int c,int fa)
{
	op++;
	s[op].c=c;
	s[op].son=-1;
	s[op].num=1e+9;
	s[op].next=head[fa];
	head[fa]=op;
	head[op]=-1;
}
int ppp;
void puls(int a[],int b[],int &alen,int &blen)
{
	for(int i=1;i<=alen;i++)
	{
		b[i]+=a[i];
	}
	blen=alen;
	for(int i=1;i<=blen;i++)
		if(b[i]>9)
		{
			b[i]-=10;
			b[i+1]+=1;
		}
	if(b[blen+1]>0) blen++;
	if(blen>100)
	{
		for(int i=1;i<=blen;i++)
			b[i]=b[i+1];
		for(int i=1;i<=alen;i++)
			a[i]=a[i+1];
		blen--;
		alen--;
	}
}

void build_x(int fa,int x[],int now,int con,int po)
{
	po--;
	if(po<0||now<=0)
	{
		if(s[fa].num>con)
			s[fa].num=con;
		return;
	}
	int i=head[fa];
	while(i!=-1)
	{
		if(s[i].c==x[now])
		{
			build_x(i,x,now-1,con,po);
			return;
		}
		i=s[i].next;
	}
	build(x[now],fa);
	i=op;
	build_x(op,x,now-1,con,po);
	if(i!=op)
	{
	 	s[i].num=s[i+1].num;
	 	if(s[i].num==0) printf("%d\n",i);
	}
}

void prime()
{
	int alen=1,blen=1;
	int con=1;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	s[0].son=-1;
	head[0]=-1;
	a[1]=1;
	build_x(0,a,1,0,40);
	b[1]=1;
	for(int i=2;i<100000;i++)
	{
		ppp=i;
		if(i&1) 
		{
			puls(a,b,alen,blen);
			//print(b,blen);
			build_x(0,b,blen,++con,40);
			
		}
		else 
		{
			puls(b,a,blen,alen);
			//print(a,alen);
			build_x(0,a,alen,++con,40);

		}
	}
	//printf("%d\n",op);
	
}

int find(int fa,char p[],int now)
{
	if(p[now]=='\0')
	{
		return s[fa].num;
	}
	int i=head[fa];
	while(i!=-1)
	{
		if(s[i].c==p[now]-'0')
			return find(i,p,now+1);
		i=s[i].next;
	}
	return -1;
}

int main()
{
	int time,con=0;
	prime();
	scanf("%d",&time);
	char s[43];
	while(time--)
	{
		printf("Case #%d: ",++con);
		scanf("%s",s);
		printf("%d",find(0,s,0));
		printf("\n");
	}
	return 0;
}