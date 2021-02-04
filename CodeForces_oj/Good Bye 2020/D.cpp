#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
	int val;
	int num;
}s[200003];
int n;

bool cmp(const point &a,const point &b)
{
	return a.val>b.val;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int time,x,y,j;
	long long ans;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i].val);
			ans+=(long long)s[i].val;
			s[i].num=-1;
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			s[x-1].num++;
			s[y-1].num++;
		}
		sort(s,s+n,cmp);
		printf("%lld",ans);
		j=0;
		for(int i=2;i<n;i++)
		{
			while(s[j].num==0) j++;
			ans+=(long long)s[j].val;
			printf(" %lld",ans);
			s[j].num--;
		}
		printf("\n");
	}
	return 0;
}