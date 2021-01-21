#include <cstdio>
#include <cstring>
using namespace std;

short num[29];

int main()
{
	int i,k,len;
	char s[1003];
	while(scanf("%s",s)==1)
	{
		memset(num,0,sizeof(num));
		for(i=0;s[i]!='\0';i++)
			num[s[i]-'a']++;
		len=i;
		k=0;
		for(i=0;i<26;i++)
			if(num[i]&1)
				k++;
		if(k==0||(k==1&&(len&1)))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
