#include <cstdio>
using namespace std;
char s[12];

int main()
{
	int i,k,p;
	while(scanf("%s",s)==1)
	{
		p=0;
		for(i=0;i<10;i++)
		{
			if(s[i]=='?') k=i;
			else
			{
				if(s[i]=='X') p+=10*(10-i);
				else p+=(s[i]-'0')*(10-i);
				p%=11;
			}
		}
		p=11-p;
		if(p==11) p=0;
		for(i=0;i<=10;i++)
		{
			if(i*(10-k)%11==p)
			{
				p=i;break;
			}
		}
		if(p==10) s[k]='X';
		else s[k]='0'+p;
		printf("%s\n",s);
	}
	return 0;
} 
