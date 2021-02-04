#include <cstdio>
#include <cstring>
using namespace std;
const int inf=1003;
char sample[inf];
bool is_circular[inf][inf];
int dpl[inf],dpr[inf];

void process()
{
	memset(is_circular,0,sizeof(is_circular));
	int len=strlen(sample);
	for(int i=0;i<len;i++)
	{
		is_circular[i][i]=true;
		if(sample[i]==sample[i+1])
			is_circular[i][i+1]=true;
	}
	for(int xlen=2;xlen<=len-1;xlen++)
		for(int s=0;s+xlen<len;s++)
			if(sample[s]==sample[s+xlen]&&is_circular[s+1][s+xlen-1]==true)
				is_circular[s][s+xlen]=true;
}


int Min(const int &a,const int &b)
{
	return a>b?b:a;
}

void core_dp()
{
	int len=strlen(sample),ans=inf;
	for(int i=0;i<len;i++)
	{
		if(is_circular[0][i])
			dpl[i]=1;
		else dpl[i]=i+1;
		for(int j=0;j<i;j++)
		{
			if(is_circular[j+1][i])
			{
				dpl[i]=Min(dpl[i],dpl[j]+1);
			}
		}
	}
	for(int i=len-1;i>=0;i--)
	{
		if(is_circular[i][len-1]) 
			dpr[i]=1;
		else dpr[i]=len-i;
		for(int j=len-1;j>i;j--)
		{
			if(is_circular[i][j-1])
			{
				dpr[i]=Min(dpr[i],dpr[j]+1);
			}
		}
	}
	if(is_circular[0][len-1]) ans=1;
	for(int i=1;i<len;i++)
	{
		if(dpl[i-1]+dpr[i]<ans)
			ans=dpl[i-1]+dpr[i];
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s",sample);
		process();
		core_dp();
	}
	return 0;
}