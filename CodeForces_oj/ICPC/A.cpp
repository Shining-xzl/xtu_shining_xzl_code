#include <cstdio>
#include <algorithm>
using namespace std;
const int lim=1e5+3;
int n,m,p;
struct point
{
	double x,y;
}lq[lim],rq[lim],cq[lim];
/*
lq 左边界队列
rq 右边界队列
cq 摄像机队列
*/
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))

double q[lim];

void initial()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%lf %lf",&lq[i].x,&lq[i].y);
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i)
		scanf("%lf %lf",&rq[i].x,&rq[i].y);
	scanf("%d",&p);
	for (int i = 1; i <= p; ++i)
		scanf("%lf %lf",&cq[i].x,&cq[i].y);
}

double get(const point &x,const point &y,double yy)
{
	double k;
	k = (y.x - x.x) * (yy - x.y) / (y.y - x.y);
	k = x.x + k ;
	return k;
}

double ans;
void work()
{
	int pl = 1, pr = 1, pc = 1, len;
	double x0,x1,yy,temp;
	ans = rq[1].x - lq[1].x;
	if(ans < 0.0) ans = 0.0;
	while(cq[pc].y < lq[1].y) ++pc;
	lq[0].x = -2e11;
	lq[0].y = lq[1].y - 0.3;
	rq[0].x = 2e11;
	rq[0].y = rq[1].y - 0.3;
	while(pl <= n && pr <= m)
	{
		len = 0;
		if(pc <= p && cq[pc].y <= lq[pl].y && cq[pc].y <= rq[pr].y)
		{
			yy = cq[pc].y;
			x0 = get(lq[pl-1],lq[pl],yy);
			x1 = get(rq[pr-1],rq[pr],yy);
			do
			{
				if(cq[pc].x > x0 && cq[pc].x < x1)
					q[++len] = cq[pc].x;
				++pc;
			}while(pc <= p && cq[pc].y == yy);
			if(len >= 1)
				sort(q+1,q+len+1,cmp);
			q[0] = x0;
			q[++len] = x1;
			temp = 0.0;
			for(int i = 0; i < len; ++i)
				temp = Max(temp,q[i+1] - q[i]);
			ans = Min(ans,temp);
		}
		else if(lq[pl].y <= rq[pr].y)
		{
			yy = lq[pl].y;
			x0 = lq[pl].x;
			x1 = get(rq[pr-1],rq[pr],yy);
			ans = Min(ans,x1 - x0);
			++pl;
		}
		else
		{	
			yy = rq[pr].y;
			x0 = get(lq[pl-1],lq[pl],yy);
			x1 = rq[pr].x;
			ans = Min(ans,x1 - x0);
			++pr;
		}
	}
	printf("%.6lf\n", ans);
}

int main()
{
	initial();
	work();
	return 0;
}