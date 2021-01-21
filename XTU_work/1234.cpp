#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s[]={"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto","if","int","long",
"register","return","short","signed","sizeof","static","struct","switch",
"typedef","union","unsigned","void","volatile","while"};
string a;

bool find()
{
	int i,len=a.size();
	if(a[0]>='0'&&a[0]<='9') return 0;
	for(i=0;i<len;i++)
		if(a[i]!='_'&&!(a[i]>='A'&&a[i]<='Z')&&!(a[i]>='a'&&a[i]<='z')&&
			!(a[i]>='0'&&a[i]<='9'))
			return 0;
	for(i=0;i<32;i++)
		if(a==s[i]) return 0;
	return 1;
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		cin>>a;
		if(find()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
