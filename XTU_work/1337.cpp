#include <cstdio>
#include <cstring>
using namespace std;
char a[103],b[103];
int lena,lenb;

bool right(int s,int p)
{
	int i;
	for(i=0;i<lenb;i++)
	{
		if(b[i]!=a[s]) 
			return false;
		s+=p;
		if(s>=lena) s-=lena;
		if(s<0) s+=lena;
	}
	return true;
}

int main()
{
	int time,i;
	bool flag;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%s%s",a,b);
		lena=strlen(a);
		lenb=strlen(b);
		flag=0;
		for(i=0;i<lena;i++)
			if(right(i,1)||right(i,-1))
			{
				flag=1;
				break;
			}
		if(flag)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
