#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int n,m;
int mate[12][10003],num;
map< string,int > ID;
map< pair<int,int>,int > op;

int get_ID(string &a)
{
	if(!ID.count(a)) 
		ID[a]=(++num);
	return ID[a];
}

int ansx1,ansx2,ansy1,ansy2;

bool right()
{
	int a,b,i;
	for(a=1;a<m;a++)
	{
		for(b=a+1;b<=m;b++)
		{
			op.clear(); 
			for(i=1;i<=n;i++)
			{
				if(op.count(pair<int,int>(mate[a][i],mate[b][i])))
				{
					ansx1=op[pair<int,int>(mate[a][i],mate[b][i])];
					ansx2=i;
					ansy1=a;
					ansy2=b;
					return false;
				}
				else op[pair<int,int>(mate[a][i],mate[b][i])]=i;
			}
		}
	}
	return true;
}

int main()
{
	string temp;
	int len,i,j,con;
	char ss[83];
	while(scanf("%d%d",&n,&m)==2)
	{
		gets(ss);
		ID.clear();
		num=0;
		for(i=1;i<=n;i++)
		{
			gets(ss);
			con=0;
			len=strlen(ss);
			temp="";
			for(j=0;j<=len;j++)
			{
				if(ss[j]==','||j==len)
				{
					con++;
					mate[con][i]=get_ID(temp);
					temp="";
				}
				else temp+=ss[j];
			}
		}
		if(right()) printf("YES\n");
		else
		{
			printf("NO\n");
			printf("%d %d\n%d %d\n",ansx1,ansx2,ansy1,ansy2);
		}
	}
	return 0;
}
