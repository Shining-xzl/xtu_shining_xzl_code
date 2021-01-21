#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector< vector<string> > v;
unsigned int len[189];

void initial()
{
	char in[187];
	string tmp;
	int i;
	while(gets(in))
	{
		vector<string> temp;
		i=0;
		do
		{
			while(in[i]==' ') i++;
			while(in[i]>=33&&in[i]<=126) tmp+=in[i++];
			if(tmp!="") temp.push_back(tmp),tmp="";
		}while(in[i]!='\0');
		v.push_back(temp);
	}
}

void core()
{
	unsigned int len_1,len_2,i,j,len_x;
	len_1=v.size();
	for(i=0;i<len_1;i++)
	{
		len_2=v[i].size();
		for(j=0;j<len_2;j++)
		{
			len_x=v[i][j].size();
			if(len_x>len[j])
				len[j]=len_x;
		}
	}
}

void out_put()
{
	unsigned int len_1,len_2,i,j,k,len_x;
	len_1=v.size();
	for(i=0;i<len_1;i++)
	{
		len_2=v[i].size();
		for(j=0;j<len_2;j++)
		{
			len_x=v[i][j].size();
			cout<<v[i][j];
			if(j!=len_2-1)
				for(k=0;k<=len[j]-len_x;k++)
					putchar(' ');
		}
		cout<<endl;
	}
}

int main()
{
	initial();
	core();
	out_put();
	return 0;
}