#include <cstdio>
#include <cstring>
using namespace std;
char s[203];
bool k[30];

bool right()
{
	memset(k,0,sizeof(k)); 
	int i,len1=0,len2=0,p;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='a'&&s[i]<='z') 
		{
			p=s[i]-'a';
			if(!k[p]) 
			{
				k[p]=1;
				len1++;
			}
		}
		else if(s[i]>='A'&&s[i]<='Z') 
		{
			p=s[i]-'A';
			if(!k[p]) 
			{
				k[p]=1;
				len1++;
			}
		}
		else if(s[i]==' ') len2++;
		if(len2>9) return 0;
		if(len1>10) return 0;
	}
	return 1;
}

int main()
{
	while(gets(s))
	{
		if(right()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
