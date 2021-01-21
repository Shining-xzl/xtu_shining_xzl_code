#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
struct box
{
	int x,y,height;
	box(int a,int b,int c)
	{
		height=c;
		if(a<b) c=a,a=b,b=c;
		x=a;
		y=b;
	};
};
vector<box> v;
bool _if[103][103];
int ans[103],len;

void dfs(int x)
{
	if(ans[x]>0) return;
	ans[x]=v[x].height;
	int max=0;
	for(int i=0;i<len;i++)
		if(_if[x][i])
		{
			dfs(i);
			max=(max<ans[i]?ans[i]:max);
		}
	ans[x]+=max;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y,z,nowcon=0;
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			v.push_back(box(x,y,z));
			v.push_back(box(x,z,y));
			v.push_back(box(z,y,x));
		}
		len=v.size();
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
			{
				box *a=&v[i];
				box *b=&v[j];
				if(a->x>b->x&&a->y>b->y)
					_if[i][j]=true;
			}
		int max=0;
		for(int i=0;i<len;i++)
		{
			dfs(i);
			if(ans[i]>max)
				max=ans[i];
		}
		printf("Case %d: maximum height = %d\n",++nowcon,max);
		v.clear();
		memset(_if,false,sizeof(_if));
		memset(ans,0,sizeof(ans));
	}
	return 0;
}