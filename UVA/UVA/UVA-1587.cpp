#include <cstdio>
using namespace std;

short a[6][2];

inline bool right()
{
	bool flag,Is[6]={0};
	short i,len=0,num[7],j;
	for(i=0;i<6;i++)
	{
		if(!Is[i])
			for(j=i+1;j<6;j++)
			{
				if((!Is[j])&&
				((a[i][0]==a[j][0]&&a[i][1]==a[j][1])||(a[i][0]==a[j][1]&&a[i][1]==a[j][0])))
				{
					len++;
					Is[j]=true;
					break;
				}
			}
	}
	if(len!=3) return false;
	len=0;
	if(a[0][0]==a[0][1]) num[++len]=a[0][0];
	else num[++len]=a[0][0],num[++len]=a[0][1];
	for(i=1;i<6;i++)
	{
		flag=1;
		for(j=1;j<=len;j++)
			if(a[i][0]==num[j])
			{
				flag=0;
				break;
			}
		if(flag) num[++len]=a[i][0];
		flag=1;
		for(j=1;j<=len;j++)
			if(a[i][1]==num[j])
			{
				flag=0;
				break;
			}
		if(flag) num[++len]=a[i][1];
	}
	if(len<=3)
		return true;
	else return false;
}

void initial()
{
	short i=0;
	while(scanf("%d%d",&a[i][0],&a[i][1])==2)
	{
		while(++i<6) scanf("%d%d",&a[i][0],&a[i][1]);
		if(right()) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
		i=0;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	initial();
	return 0;
}
