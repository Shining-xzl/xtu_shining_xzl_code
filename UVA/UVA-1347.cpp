#include <cstdio>
#include <cmath>
using namespace std;
int n;
int x[1002],y[1002];
float ans[1003][1003];

float get_distance(int a,int b)
{
	float temp;
	temp=(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
	temp=sqrt(temp);
	return temp;
}

void core_dp()
{
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ans[i][j]=0xffffffffffffffff;
	ans[1][2]=get_distance(1,2);
	float temp,out_ans=0xffffffffffffffff;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			temp=ans[i][j]+get_distance(j,j+1);
			if(temp<ans[i][j+1])
				ans[i][j+1]=temp;
			temp=ans[i][j]+get_distance(i,j+1);
			if(temp<ans[j][j+1])
				ans[j][j+1]=temp;
		}
	for(int i=1;i<n;i++)
	{
		temp=ans[i][n]+get_distance(i,n);
		if(temp<out_ans)
			out_ans=temp;
	}
	printf("%.2f\n",out_ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		core_dp();
	}
	return 0;
}