#include <cstdio>
#include <cstring>
using namespace std;

int num[29];
char s[1003];

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int i,a,max,j,con=0;
	while(scanf("%s",s)==1)
	{
		memset(num,0,sizeof(num));
		for(i=0;s[i]!='\0';i++)
			num[s[i]-'A']++;
		i=0;
		while(!num[i]&&i<26) i++;
		a=num[i++];
		max=a;
		while(i<26)
		{
			if(num[i]>0) a=gcd(a,num[i]);
			if(num[i]>max) max=num[i];
			i++;
		}
		max/=a;
		for(i=0;i<26;i++)
			num[i]/=a;
		while(max>0)
		{
			j=25;
			while(num[j]<max) j--;
			for(i=0;i<=j;i++)
				if(num[i])
					printf("%c",num[i]>=max ? '*':' ');	
			printf("\n");
			max--;
		}
		for(i=0;i<26;i++)
			if(num[i]) 
				printf("%c",i+'A');
		printf("\n\n");
	}
	return 0;
}
