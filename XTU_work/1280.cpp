#include <cstdio>
#include <cstring>
using namespace std;
const __int64 MOD=1000000007;
__int64 k[1003];

int main()
{
	char s[1003];
	int i,len;
	__int64 ans; 
	k[0]=1;
	for(i=1;i<=1000;i++)
		k[i]=(k[i-1]*26)%MOD;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		ans=k[len];
		for(i=0;i<len;i++)
			ans=(ans+k[len-i-1]*(s[i]-'a'))%MOD;
		printf("%I64d\n",ans);
	}
	return 0;
}
