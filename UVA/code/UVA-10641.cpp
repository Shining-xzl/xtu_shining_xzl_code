/*
���㼸�μ�dp
��״�ġ������鷳���� 
dp[strat][len]�����start���������len���߾��ɸ��ǵ���С���� 
״̬ת�ơ����������Ű��
�������� s[i],l[i]�����i����Դ���������s[i]�����,l[i]���ߡ�

Ҫ�����i����Դ����ıߣ�
����һ���ߣ��˵�(x1,y1),(x2,y2)�����������ϵ��ֻҪ�ҵ�һ�����ڶ�����ڲ���
����ߵķ���ax+by+c=0;�ڵ�Ϊ(x0,y0),��ô��x0*a+y0*b+c��*(ax+by+c)<0����˵����Դ������˱�
�ڵ�Ϊ����ε�����͵�ƽ��ֵ 
 
*/
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=0x3f3f3f3f;

int n,m;
struct point
{
	float x,y;
}v[32],light[1003];
int c[1003];
float midx,midy;
int dp[32][32];
int s[1003],l[1003];

bool check(float x1,float y1,float x2,float y2,float x,float y)//�ж��Ƿ����ֱ������
{
	float a,b,c;
	a=y1-y2;
	b=x2-x1;
	c=x1*y2-x2*y1;
	if((x*a+y*b+c)*(midx*a+midy*b+c)<0) return 1;//��ѧ֪ʶ 
	else return 0;
}

void process()
{
	int pre,now;
	bool flag;
	for(int i=0;i<m;i++)
	{
		pre=0;
		flag=0;
		l[i]=0;
		for(int j=n-1;j>=0;j--)//���򣬷��㻷�Ĵ��� 
		{
			now=j;
			if(check(v[pre].x,v[pre].y,v[now].x,v[now].y,light[i].x,light[i].y))
			{
				if(!flag) s[i]=now;//���ϸ������ 
				l[i]++;
			}
			else if(l[i]>0) flag=1;//���������Ͽ� 
			pre=now;
		}
	}
	
}

int Min(int a,int b)
{
	return a<b?a:b;
}

int addx_len(int i,int start,int len)//�ж��Ƿ�ɽ�ϣ���ϸ˼������״����ģ�� 
{
	int end=start+len;
	int xs=s[i],xe=s[i]+l[i];
	if(xe<n)//�ؼ��㣬��ͼ��֪ 
		end%=n;
	if(end>=xs&&end<=xe)//�ɽ�� 
	{
		return xe-end+len;
	}
	else return len;
}

void core_dp()
{
	memset(dp,INF,sizeof(dp));
	for(int i=0;i<n;i++)//��ʼ�� 
		dp[i][0]=0;
	for(int len=0;len<n;len++)//���� 
		for(int start=0;start<n;start++)//��� 
		{	
			if(dp[start][len]==INF) continue;
			for(int i=0;i<m;i++)//��Դ���ڵ����㣬����״̬�������ԣ�ͬ���Ĺ�Դ����ڶ������ã����Բ�ͬ�ڱ������� 
			{
				int lenx=addx_len(i,start,len);
				dp[start][lenx]=Min(dp[start][lenx],dp[start][len]+c[i]);
			}
		}
	int MIN=1e9;
	for(int i=0;i<n;i++)
		MIN=Min(MIN,dp[i][n]);
	
	if(MIN==1e9)
		printf("Impossible.\n");
	else printf("%d\n",MIN);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	midx=0,midy=0;
	while(scanf("%d",&n)&&n)
	{
		midx=midy=0;
		for(int i=0;i<n;i++)
			scanf("%f%f",&v[i].x,&v[i].y),midx+=v[i].x,midy+=v[i].y;
		midx/=n;
		midy/=n;//�ڵ� 
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%f%f%d",&light[i].x,&light[i].y,&c[i]);
		process();//�ӹ��������� 
		core_dp();
	}
	return 0;
} 
