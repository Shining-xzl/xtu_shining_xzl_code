#include <cstdio>
#include <cstring>
using namespace std;

const char* rc="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* ans[]={" -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string."," -- is a mirrored palindrome."};

char get_r(char x)
{
	if(x>='A'&&x<='Z') return rc[x-'A'];
	else return rc[x-23];
}

int main()
{
	// freopen("in.txt","r",stdin);
	int if_a,if_b,len;
	char s[25];
	while(scanf("%s",s)==1)
	{
		if_a=1;
		if_b=1;
		len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]!=s[len-i-1]) if_a=0;
			if(get_r(s[i])!=s[len-i-1]) if_b=0;
		}
		printf("%s%s\n\n",s,ans[(if_b<<1)+if_a]);
	}
	return 0;
}