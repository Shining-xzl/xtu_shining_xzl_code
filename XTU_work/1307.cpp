#include <cstdio>
using namespace std;
__int64 s[1800],len;

void get()
{
	int i,j;
	__int64 temp,k,l=1;
	s[++len]=0;
	for(i=2;i<=60;i++)
	{
		temp=(l<<i)-1;
		for(j=i-2;j>=0;j--)
		{
			k=temp^(l<<j);
			s[++len]=k;
		}
	}
	
}


int main()
{
	int time,i,con;
	__int64 n,m;
	get();
	scanf("%d",&time);
	while(time--)
	{
		scanf("%I64d%I64d",&n,&m);
		con=0;
		for(i=1;i<=len;i++)
		{
			if(s[i]>=n&&s[i]<=m)
				con++;
		}
		printf("%d\n",con);
	}
	return 0;
}
