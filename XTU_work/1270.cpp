#include <cstdio>
using namespace std;
const int TNT=8877691;
__int64 s[TNT+3],len;
short k[TNT+3];
//构造类程序 
void get()
{
	int i,p,l;
	s[++len]=0;
	for(i=1;i<=9;i++)
	{
		s[++len]=i;
		k[len]=(1<<i);
	}
	l=2;
	while(l<=len)
	{
		p=len;
		while(l<=p)
		{
			for(i=0;i<=9;i++)
				if((k[l]&(1<<i))==0)
				{
					s[++len]=(s[l]<<3)+(s[l]<<1)+i; 
					k[len]=k[l]+(1<<i);
				}
			l++;
		}
	}
}

int main()
{
	get();
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%I64d\n",s[n]);
	}
	return 0;
}
