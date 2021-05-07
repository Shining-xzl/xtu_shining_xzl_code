#include <cstdio>
using namespace std;
int d,s,b,flag;
char so[7][64003];

bool check()
{
	int len=s*b,con,k;
	char *now,*p;
	for(int i=0;i<len;i++)
	{
		con=0;
		k=-1;
		for(int j=0;j<b;j++)
		{
			now=&so[j][i];
			if(*now=='x') con++,p=&so[j][i];
			else if(k==-1)
			{
				if(*now=='1') k=1;
				else k=0;
			}
			else 
			{
				if(*now=='1') k^=1;
				else k^=0;
			}
			if(con>1) return 0;
		}
		if(con==1)
		{
			if((k^flag)==1) *p='1';
			else *p='0';
		}
		if(k!=flag) return 0;
	}
	return 1;
}

int main()
{
	freopen("in.txt","r",stdin);
	char p[2];
	int con=0;
	while(scanf("%d%d%d",&d,&s,&b)==3)
	{
		scanf("%s",p);
		if(p[0]=='E') flag=0;
		else flag=1;
		for(int i=0;i<d;i++)
			scanf("%s",so[i]);
		if(check())
		{
			printf("Disk set %d is valid, contents are :",++con);
			printf("\n");
		}
		else printf("Disk set %d is invalid.\n",++con);
	}
	return 0;
}