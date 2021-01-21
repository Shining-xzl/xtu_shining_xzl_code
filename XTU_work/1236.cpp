#include <cstdio>
using namespace std;
int f[30];
int k[1000002];
//¼ÇÒä»¯ËÑË÷ 
int get_ans(int a,int len)
{
	if(len<0) return 0;
	if(a==0) return 0;
	if(a==f[len]) k[a]=(1<<len);
	if(k[a]) return k[a];
	int ans,temp=0;
	if(a>f[len])
		temp=get_ans(a-f[len],len);
	if(temp!=0) ans=temp+(1<<len);
	else ans=get_ans(a,len-1);
	k[a]=ans;
	return ans;
}

int main()
{
	f[0]=1;
	f[1]=2;
	for(int i=2;i<=28;i++)
		f[i]=f[i-1]+f[i-2];
	int time,n;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		printf("%d\n",get_ans(n,28));
	}
	return 0;
}
