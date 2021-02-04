#include <cstdio>
#include <cstring> 
using namespace std;
const int INF=0x3f3f3f3f,inf=-0x3f3f3f3f;
int Max[504][504],Min[504][504],pos[504],pre[504],dp[503][503],ans[503];
int n,s[504];
bool uniq[504][504];
int _MAX(int a,int b)
{
	return a>b?a:b;
}

int _MIN(int a,int b)
{
	return a<b?a:b;
}

void initail()
{
	memset(pos,0,sizeof(pos));
	memset(pre,0,sizeof(pre));
	memset(uniq,0,sizeof(uniq));
	memset(Max,inf,sizeof(Max));
	memset(Min,INF,sizeof(Min));
	memset(ans,INF,sizeof(ans));
	memset(dp,INF,sizeof(dp));
	/*
	特别巧妙的处理方法
	pre+pos -> uniq
	Max,uniq组合判断，是否为合法区间 
	*/ 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		if(pos[s[i]]) pre[i]=pos[s[i]];
		pos[s[i]]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			Max[i][j]=_MAX(Max[i][j-1],s[j]);
			Min[i][j]=_MIN(Min[i][j-1],s[j]);
			if(j==i||(pre[j]<i&&uniq[i][j-1]))
				uniq[i][j]=1;
		}
}

int solve(int l,int r)//显然是个区间dp 
{
	int &ans=dp[l][r];
	int numl,numr,num,temp;
	if(ans<INF) return ans;
	if(l==r) return ans=0;
	for(int i=l;i<r;i++)
	{
		numl=solve(l,i);
		numr=solve(i+1,r);
		num=0;
		temp=_MAX(Min[l][i],Min[i+1][r]);
		if(temp==Min[i+1][r])
		{
			for(int j=l;j<=i;j++)
				if(s[j]<temp) num++;
		}
		else
		{
			for(int j=i+1;j<=r;j++)
				if(s[j]<temp) num++;
		}
		ans=_MIN(ans,numl+numr+r-l+1-num);
		//思考为什么是 numl+numr+r-l+1-num
		//只有最小的一套不同打开，其他的全部都要打开 
		//画个图就明白了（代价的计算） 
	}
	return ans;
}

void work()
{
	ans[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(uniq[i][j]&&Max[i][j]==j-i+1&&ans[i-1]!=INF)
			{
				ans[j]=_MIN(ans[j],ans[i-1]+solve(i,j));//正解dp 
			}
	if(ans[n]<INF) printf("%d\n",ans[n]);
	else printf("impossible\n");
}

int main()
{
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)==1)
	{
		initail();
		work();	
	}
	return 0;
} 
