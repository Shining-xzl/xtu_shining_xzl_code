#include <cstdio>
using namespace std;

#define Min(x,y) ((x)<(y)?(x):(y))

struct node
{
	int a,b,c;
	void sort()
	{
		int x;
		if(a>b) x=a,a=b,b=x;
		if(a>c) x=a,a=c,c=x;
		if(b>c) x=c,c=b,b=x;
	}
	int go_back(int num)
	{
		int dis1,dis2,mul,sum=0;
		while(num>0)
		{
			dis1=b-a;
			dis2=c-b;
			if(dis1==dis2) return sum;
			if(dis1<dis2)
			{
				mul=Min(num,(dis2-1)/dis1);
				dis2=dis2-dis1*mul;
				b=c-dis2;
				a=b-dis1;
			}
			else
			{
				mul=Min(num,(dis1-1)/dis2);
				dis1=dis1-dis2*mul;
				b=a+dis1;
				c=b+dis2;
			}
			num-=mul;
			sum+=mul;
		}
		return sum;
	}
	bool operator == (const node& x) const
	{
		return a==x.a&&b==x.b&&c==x.c;
	}
};

int main()
{
	 freopen("in.txt","r",stdin);
	node now,pre;
	scanf("%d%d%d",&pre.a,&pre.b,&pre.c);
	scanf("%d%d%d",&now.a,&now.b,&now.c);
	pre.sort();	now.sort();
	node d1=pre,d2=now;
	int a,b,ans;
	a=d1.go_back(1e9);
	b=d2.go_back(1e9);
	printf("%d %d %d\n",d1.a,d1.b,d1.c);
	printf("%d %d %d\n",d2.a,d2.b,d2.c);
	if(d1==d2)
	{
		int l=0,r,mid;
		printf("YES\n");
		if(a<b) now.go_back(b-a),r=a,ans=b-a;
		else pre.go_back(a-b),r=b,ans=a-b;
		while(l<r)
		{
			mid=l+r>>1;
			d1=now;
			d2=pre;
			d1.go_back(mid);
			d2.go_back(mid);
			if(d1==d2) r=mid;
			else l=mid+1;
		}
		printf("%d\n",ans+l*2);
	}
	else printf("NO\n");
	return 0;
}
