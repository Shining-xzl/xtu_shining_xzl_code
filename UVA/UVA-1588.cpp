#include <cstdio>
#include <cstring>
using namespace std;
char S1[103],S2[103];

inline short get_ans(char S1[],char S2[])
{
	short len1,len2,i,j,ans;
	bool flag;
	len1=strlen(S1);
	len2=strlen(S2);
	ans=len1+len2;
	for(i=0;i<len1;i++)
	{
		flag=1;
		for(j=0;j<len2&&j+i<len1;j++)
		{
			if(S1[j+i]+S2[j]>99)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(len2+i>len1) ans=len2+i;
			else ans=len1;			
			break;
		}
	}
	return ans;
}

int main()
{
	short ans,k;
//	freopen("in.txt","r",stdin);
	while(scanf("%s%s",&S1,&S2)==2)
	{
		ans=get_ans(S1,S2);
		k=get_ans(S2,S1);
		if(k<ans) ans=k;
		printf("%d\n",ans);
	}
	return 0;
}
