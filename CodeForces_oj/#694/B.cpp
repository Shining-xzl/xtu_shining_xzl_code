#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,x;
struct num
{
	int val;
	int num;
};
queue<num> q;
LL ans;
int main()
{
//	freopen("in.txt","r",stdin);
	int time;
	num temp;
	scanf("%d",&time);
	while(time--)
	{
		while(!q.empty()) q.pop();
		scanf("%d%d",&n,&x);
		ans=0;
		while(n--)
		{
			scanf("%d",&temp.val);
			temp.num=temp.val;
			q.push(temp);
			ans+=(LL)temp.val;
		}
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(temp.num%x!=0) break;
			ans+=(LL)temp.val;
			temp.num/=x;
			q.push(temp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}