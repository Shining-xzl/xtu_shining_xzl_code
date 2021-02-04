#include <cstdio>
using namespace std;

int len;
int lx,rx,l,r;
bool p[103];
char s[103];

bool check()
{
	int ll=l;
	lx=1;
	rx=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]==s[ll]&&p[i]==0)
		{
			if(ll==l) lx=i;
			if(ll==r) rx=i;
			ll++;
		}
		if(ll>r) break;
	}
	if(ll>r) return 1;
	else return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,m,ll,rr;
	bool fl;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&len,&m);
		scanf("%s",s);
		while(m--)
		{
			scanf("%d%d",&l,&r);
			l--;
			r--;
			check();
			if(rx-lx==r-l)
			{
				fl=0;
				ll=lx;
				rr=rx;
				for(int i=ll;i<=rr;i++)
				{
					p[i]=1;
					if(check())
					{
						fl=1;
						p[i]=0;
						break;
					}
					p[i]=0;
				}
				if(fl) printf("YES\n");
				else printf("NO\n");
			}
			else printf("YES\n");
		}
	}
	return 0;
}