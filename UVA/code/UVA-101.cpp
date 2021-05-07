#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> v[27];

void get_find(int a,int &x,int &y)
{
	int i,j,end;
	for(i=0;i<n;i++)
	{
		end=v[i].size();
		for(j=0;j<end;j++)
		{
			if(v[i][j]==a)
			{
				x=i;
				y=j;
				return;
			}
		}
	}
	return;
}

void x_clear(int x,int y)
{
	int i,temp,end=v[x].size();
	for(i=y;i<end;i++)
	{
		temp=v[x][i];
		v[temp].push_back(temp);
	}
	v[x].resize(y);
}

int main()
{
	freopen("in.txt","r",stdin);
	char s1[6],s2[6];
	int a,b;
	int i,ax,ay,bx,by;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		v[i].push_back(i);
	while(scanf("%s",s1)==1)
	{
		if(s1[0]=='q') break;
		scanf("%d%s%d",&a,s2,&b);
		get_find(a,ax,ay);
		get_find(b,bx,by);
		if(ax==bx) continue;
		if(s1[0]=='m')
			x_clear(ax,ay+1);
		if(s2[1]=='n')
			x_clear(bx,by+1);
		v[bx].insert(v[bx].end(),v[ax].begin()+ay,v[ax].end());
		v[ax].resize(ay);
	}
	for(i=0;i<n;i++)
	{
		printf("%d:",i);
		b=v[i].size();
		for(a=0;a<b;a++)
			printf(" %d",v[i][a]);
		printf("\n");
	}
	return 0;
}