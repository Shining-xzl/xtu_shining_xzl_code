#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int s[502];
__int64 name[502];
int len=0;

int get(int p)
{
    if(p<13) return 32;
    else if(p<25) return 16;
    else if(p<49) return 8;
    else if(p<97) return 4;
    else if(p<193) return 2;
    else return 1;
}

int find(__int64 &namex)
{
	for(int i=0;i<len;i++)
		if(name[i]==namex)
			return i;
	name[len]=namex;
	s[len]=0;
	len++;
	return len-1;
}

int main()
{
	char c[12];
	__int64 namex;
	int p,max=0,i,j;
	while(scanf("%s%I64d%d",c,&namex,&p)==3)
	{	
		i=find(namex);
		s[i]+=get(p);
		if(s[i]>max) max=s[i];
	}
	for(i=0;i<len;i++)
		s[i]=(int)(100.5+log(1.0+(s[i]*1.0-max*1.0)/(max*1.0))*10);
	for(i=0;i<len;i++)
	{
		p=i;
		for(j=i+1;j<len;j++)
		{
			if(s[p]<s[j]) p=j;
			else if(s[p]==s[j]&&name[j]<name[p]) p=j;
		}
		if(p!=i)
		{
			j=s[i];
			s[i]=s[p];
			s[p]=j;
			namex=name[i];
			name[i]=name[p];
			name[p]=namex;
		}
		printf("%I64d %d\n",name[i],s[i]);
	}
	return 0;
}
