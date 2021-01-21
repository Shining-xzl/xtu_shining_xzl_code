#include <cstdio>
#include <cstring>
using namespace std;

int n,k;
struct all
{
	int a[4];
	int x,y;
}s[103];
int ans[6],len;

bool if_right()
{
	int i,j,xx,yy,l;
	bool use[5];
	for(i=1;i<=k;i++)
	{
		memset(use,0,sizeof(use));
		xx=0;
		yy=0;
		for(j=0;j<4;j++)
		{
			if(s[i].a[j]==ans[j])
			{
				xx++;
				use[j]=true;
			}
		}
		for(j=0;j<4;j++)
		{
			if(use[j]) continue;
			for(l=0;l<4;l++)
			{
				if(use[l]) continue;
				if(ans[j]==s[i].a[l])
				{
					yy++;
					break;
				}
			}
		}
		if(xx!=s[i].x||yy!=s[i].y)
			return false;
	}
	return true;
}

int main()
{
	int i,j,l,p;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		len=0;
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			for(j=0;j<4;j++)
				scanf("%d",&s[i].a[j]);
			scanf("%d%d",&s[i].x,&s[i].y);
		}
		for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            	if(i!=j)
                    for(l=1;l<=n;++l)
                        if(l!=i&&l!=j)
                            for(p=1;p<=n;p++)
                                if(p!=i&&p!=j&&p!=l)
                                {
                                	ans[0]=i;
                                	ans[1]=j;
                                	ans[2]=l;
                                	ans[3]=p;
                                	if(if_right())
                                    {
                                    	printf("%d %d %d %d\n",i,j,l,p);
                                    	len++;
                                    }
                                }
                                    
		printf("%d\n",len);
	}
	return 0;
}