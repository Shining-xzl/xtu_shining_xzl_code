#include <cstdio>
using namespace std;

int n,sum_1,sum_0,num_0,num_1;
int num[53];
int result[53],temp[53];
bool b[53],flag;

void core(int now,int sum)
{
	if(now>num_1)
	{
		flag=1;
		return;
	}
	else
	{
		for(int i=1;i<=num_1;i++)
		{
			if(!b[i]&&sum+temp[i]!=0)
			{
				b[i]=1;
				result[now]=temp[i];
				core(now+1,sum+temp[i]);
				b[i]=0;
			}
			if(flag) return;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	int time,i,sum;
	scanf("%d",&time);
	while(time--)
	{
		sum_1=0;
		sum_0=0;
		num_0=0;
		num_1=0;
		flag=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>0) sum_1+=num[i];
			else if(num[i]<0) sum_0+=num[i];
			else num_0++;
		}
		if(sum_1+sum_0==0)
			printf("NO\n");
		else
		{
			sum=0;
			printf("YES\n");
			if(sum_1>-sum_0)
			{
				for(i=1;i<=n;i++)
				{
					if(num[i]>0) printf("%d ",num[i]),sum+=num[i];
					else if(num[i]<0) temp[++num_1]=num[i];
				}
			}	
			else
			{
				for(i=1;i<=n;i++)
				{
					if(num[i]<0) printf("%d ",num[i]),sum+=num[i];
					else if(num[i]>0) temp[++num_1]=num[i];
				}
			}
			core(1,sum);
			for(i=1;i<=num_1;i++)
				printf("%d ",result[i]);
			for(i=1;i<=num_0;i++)
				printf("0 ");
			printf("\n");
		}
	}
	return 0;
}