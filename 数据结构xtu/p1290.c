#include <stdio.h>

#define lim 10003
int a[lim],b[lim],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	i=1;
	j=1;
	int pre=-1;
	while(i<=n||j<=m)
	{
		if(i>n) 
		{
			if(pre!=b[j])
				printf("%d ",b[j]),pre=b[j];
			j++;
		}
		else if(j>m)
		{
			if(pre!=a[i])
				printf("%d ",a[i]),pre=a[i];
			i++;
		} 
		else if(a[i]<=b[j]) 
		{
			if(pre!=a[i])
				printf("%d ",a[i]),pre=a[i]; 
			i++;
		}
		else 
		{
			if(pre!=b[j])
				printf("%d ",b[j]),pre=b[j];
			j++;
		}
	}
	return 0;
}
