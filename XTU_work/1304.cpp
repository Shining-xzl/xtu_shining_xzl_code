#include <cstdio>
using namespace std;
int cl[103]; 
int n,c;

int get(int r)
{
	int l=r-1,ans=0,temp,cc=c;
	temp=1;
	while(1)
	{
		while(l>0&&cl[l]==cc)
		{
			temp++;
			l--;
		}
		while(r<=n&&cl[r]==cc)
		{
			temp++;
			r++;
		}
		if(temp<3) break;
		ans+=temp;
		if(l>0) cc=cl[l];
		else if(r<=n) cc=cl[r];
		else break;
		temp=0;
	}
	return ans;
}

int main()
{
	int time,i,ans,temp;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d",&n,&c);
		for(i=1;i<=n;i++)
			scanf("%d",&cl[i]);
		ans=0;
		for(i=1;i<=n;i++)
			if(cl[i]==c&&cl[i]!=cl[i-1])
			{
				temp=get(i);
				if(temp>ans)
					ans=temp;
			}
		if(ans>0) ans--;
		printf("%d\n",ans);
	}
	return 0;
} 
