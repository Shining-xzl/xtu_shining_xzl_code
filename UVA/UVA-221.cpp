#include <cstdio>
#include <algorithm>
using namespace std;
const double ee=1e-5;

struct build
{
	double l,y,h,r;
	int id;
	bool operator < (const build &a) const
	{
		return l!=a.l ? l<a.l : y<a.y;
	}
}s[103];
int n;

bool visible(int k)
{
	double l=s[k].l,r=s[k].r,h=s[k].h,y=s[k].y;
	if(l==r)
	{
		for(int i=1;i<=n;i++)
			if(i!=k&&s[i].h>=h&&s[i].y<y&&s[i].l<=l&&s[i].r>=r)
				return 0;
		return 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==k||s[i].h<h||s[i].y>y||s[i].r<l) continue;
		if(s[i].l>l) break;
		l=s[i].r;
		if(l>=r) break;
	}
	if(l>=r)
		return 0;
	else return 1;
}

int main()
{
	int con=0,i;
	double ll;
	while(scanf("%d",&n)==1&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&s[i].l,&s[i].y,&s[i].r,&ll,&s[i].h);
			s[i].r+=s[i].l;
			s[i].id=i;
		}
		sort(s+1,s+n+1);
		if(con) printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n",++con);
		printf("%d",s[1].id);
		for(i=2;i<=n;i++)
			if(visible(i)) printf(" %d",s[i].id);
		printf("\n");
	}
	return 0;
}