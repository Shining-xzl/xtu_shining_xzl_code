/*
此题翻译严重有误，推荐英文原版 
简单dp，状态限制较多 
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int TNT=0x3f3f3f3f;
char s[73];
int dp[73][4][4][3];
int len;
struct next
{
	int l,r,p;	
}step[75][4][4][3];
int get_cost(int l,int r,int lx,int rx,int f,int fx)//获取消耗值 
{
	if(f==0||fx!=f) return 1;
	if(r!=rx)
	{
		if(r+rx==3) return 7;
		else return 5;
	}
	if(l!=lx)
	{
		if(l+lx==3) return 7;
		else return 5;
	}
	return 3;
}

void process()//简单替换，将字符替换为数字，方便后面运算，上+下=3，左+右=三 
{
	len=strlen(s); 
	for(int i=0;i<len;i++)
	{
		if(s[i]=='L') s[i]=1;
		else if(s[i]=='R') s[i]=2;
		else if(s[i]=='U') s[i]=0;
		else if(s[i]=='D') s[i]=3;
		else s[i]=-1;
	}
}

bool check(int l,int r,int lx,int rx)//检查（l，r）到（lx，rx）是否合法 
{
	if(lx==rx) return 0;
	if(lx==2&&rx==1) return 0;
	if((l==0||l==3)&&r==1&&l!=lx) return 0;
	if((r==0||r==3)&&l==2&&r!=rx) return 0;
	return 1;
}

int get_point(bool flag,int l,int r,int lx,int rx)//获取动作编号 
{
	if(l==lx&&r==rx) return flag?2:1;
	if(l==lx) return 2;
	else return 1;
}

void print(int len,int l,int r,int p)//打印路径，step为路径 
{
	if(len==0) return;
	print(len-1,step[len][l][r][p].l,step[len][l][r][p].r,step[len][l][r][p].p);
	if(p==2) printf("R");
	if(p==1) printf("L");
	if(p==0) printf(".");
	return; 
}

void core_dp()
{
	memset(dp,TNT,sizeof(dp));
	int now;
	dp[0][1][2][0]=0;
	for(int i=0;i<len;i++)
		for(int l=0;l<4;l++)
			for(int r=0;r<4;r++)
			{
				if(l==r||(l==2&&r==1)) continue;
				for(int p=0;p<3;p++)
				{
					if(dp[i][l][r][p]>=TNT) continue;
					now=dp[i][l][r][p];
					if(s[i]==-1)//无需运动 
					{
						if(dp[i+1][l][r][0]>now)//不动 
						{
							dp[i+1][l][r][0]=now;//dp记录消耗值 
							step[i+1][l][r][0].p=p;//step记录路径 
							step[i+1][l][r][0].l=l;
							step[i+1][l][r][0].r=r;
						} 
						for(int k=0;k<4;k++)
						{
							if(check(l,r,k,r))//动左腿 
							{
								int point=get_point(0,l,r,k,r);//获取动作编号 
								int &x=dp[i+1][k][r][point];
								next &a=step[i+1][k][r][point];
								int cost=get_cost(l,r,k,r,p,point);//获取消耗 
								if(x>cost+now) //替换 
								{
									x=cost+now;
									a.l=l;
									a.r=r;
									a.p=p;
								}
							}
							if(check(l,r,l,k))//右腿 
							{
								int point=get_point(1,l,r,l,k);
								int &x=dp[i+1][l][k][point];
								next &a=step[i+1][l][k][point];
								int cost=get_cost(l,r,l,k,p,point);
								if(x>cost+now) 
								{
									x=cost+now;
									a.l=l;
									a.r=r;
									a.p=p;
								}
							}
						}
					}
					else//需要踩箭头 
					{
						if(check(l,r,s[i],r))//左腿 
						{
							int point=get_point(0,l,r,s[i],r);
							int &x=dp[i+1][s[i]][r][point];
							next &a=step[i+1][s[i]][r][point];
							int cost=get_cost(l,r,s[i],r,p,point);
							if(x>cost+now) 
							{
								x=cost+now;
								a.l=l;
								a.r=r;
								a.p=p;
							}
						}
						if(check(l,r,l,s[i]))//右腿 
						{
							int point=get_point(1,l,r,l,s[i]);
							int &x=dp[i+1][l][s[i]][point];
							next &a=step[i+1][l][s[i]][point];
							int cost=get_cost(l,r,l,s[i],p,point);
							if(x>cost+now) 
							{
								x=cost+now;
								a.l=l;
								a.r=r;
								a.p=p;
							}
						}
					}
				}
			}
	int ll,rr,Min=1e9,pp;
	for(int l=0;l<4;l++)
		for(int r=0;r<4;r++)
			for(int p=0;p<3;p++)
				if(Min>dp[len][l][r][p])//寻找最小值 
				{
					Min=dp[len][l][r][p];
					ll=l;rr=r;pp=p;
				}
	print(len,ll,rr,pp);
	printf("\n");
}

int main()
{
	while(scanf("%s",s)==1)
	{
		if(s[0]=='#') break;
		process();
		core_dp();
	}	
	return 0;
 } 
