#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <set>

using namespace std;
char s[10003];
int d[10003];
int k[300];

int main()
{
	int i,len,j,num,Max,lst;
	string temp;
	set<string>::iterator it;
	while(scanf("%s",s)==1)
	{
		Max=0;
		memset(k,-1,sizeof(k));
		len=strlen(s);
		num=0;
		lst=0;
		for(i=0;i<len;i++)
		{
			if(k[s[i]-'a']!=-1)
			{
				j=k[s[i]-'a'];
				if(j>=lst)
				{
					num=i-j;
					lst=j+1;
				}
				else num++;
			}
			else num++;
			k[s[i]-'a']=i;
			d[i]=num;
			if(Max<num) 
				Max=num;
		}
		set<string> ans;
		for(i=0;i<len;i++)
		{
			if(d[i]==Max)
			{
				num++;
				temp="";
				for(j=i-d[i]+1;j<=i;j++)
					temp+=s[j];
				ans.insert(temp);
			}
		}
		printf("%d\n",Max);
		for(it=ans.begin();it!=ans.end();it++)
			cout<<*it<<endl;
	}
	return 0;
} 
