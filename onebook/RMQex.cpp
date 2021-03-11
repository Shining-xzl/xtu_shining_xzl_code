#include <cstdio>
#include <map>

using namespace std;

#define max(x,y) (x)>(y)?(x):(y)

const int lim=2e5+3;
int n,m;
map<int,int> pos;
int pre[lim];
int s[lim];
int f[lim][20];
int log2[lim];

int binary_find(int stand,int lim)
{
	int mid,l=stand,r=lim;
	while(l<r)
	{
		mid=l+r>>1;
		if(pre[mid]<=stand) l=mid+1;
		else r=mid;
	}
	return l;
}

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);	
	log2[0]=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		if(i==0) pre[i]=0;
		else if(pos.count(s[i])==0) pre[i]=pre[i-1];
		else pre[i]=max(pre[i-1],pos[s[i]]+1);
		pos[s[i]]=i;
		f[i][0]=i-pre[i]+1;
		if(i) log2[i]=log2[i>>1]+1;
	}
	for(int i=1;i<20;i++)
		for(int j=0;j+(1<<i)-1<n;j++)
				f[j][i]=max(f[j][i-1],f[j+(1<<i-1)][i-1]);
	int r,l,ans,xp,p;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		xp=binary_find(l,r);
		ans=xp-l;
		if(pre[xp]>l)
		{
			p=log2[r-xp+1];
			ans=max(ans,f[xp][p]);
			ans=max(ans,f[r-(1<<p)+1][p]);
		}
		else ans++;
		printf("%d\n",ans);
	}
	return 0;
}