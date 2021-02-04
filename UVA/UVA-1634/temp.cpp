#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=105,INF=0x3f3f3f3f;
int T,m,d,ans,dp[maxn][maxn];
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    Point operator - (const Point &rhs) const {
        return Point(x-rhs.x,y-rhs.y);
    }
    bool operator < (const Point &rhs) const;
}points[maxn],center,up[maxn];  //center��ÿ��ѡ����һ��,������͹����ε����·��Ķ��㣨֮һ����uprig��center�Ϸ�����

int distant(const Point &a){
    return a.x*a.x+a.y*a.y;
}
//����������ˣ�������������ɵ�ƽ���ı������������0.5�������������
//��˵�ֵ>0��b��a����ʱ�뷽��<0,��˳ʱ��,=0���㹲��
int crossProduct(const Point &a,const Point &b){
    return a.x*b.y-b.x*a.y;
}

bool Point::operator < (const Point &rhs) const {
    int t=crossProduct(*this-center,rhs-center);
    if(t!=0) return t>0;  //center���Ϸ����㰴����ʱ��˳������
    return distant(*this-center)<distant(rhs-center);  //i��j��center���㹲�ߣ����վ������򣬺�center������ǰ��
}

void solve(){

    //dp[i][j]��(center��i)Ϊһ���ߣ���j������ű�jС�ĵ㹹�ɵ�����͹��������
    memset(dp,0,sizeof(dp));
    //���Ϸ��ĵ㰴����ʱ��˳�����У����ǣ�points[k]-center��������x��������ĽǶ�С����ǰ�棬�Ƕ���ͬ�ľ��������ǰ��
    sort(up+1,up+1+d);
    for(int i=1;i<=d;i++)
    {
    	printf("%d %d\n",up[i].x-center.x,up[i].y-center.y);
	}
	printf("*****\n");
    //͹������У���͵�˳ʱ����ת��ĵ�һ������
    for(int i=2;i<=d;++i){
        int j=i-1; //j��i˳ʱ����ת��ĵ�һ�����㣨i,j,center���㲻�ܹ��ߣ����߾Ͳ���һ���������ˣ���i,j,center����һ��������
        while(j && (!crossProduct(up[i]-center,up[j]-center))) j--;  //���i,j,center���㹲�ߣ�Ѱ����һ���ϸ�ĵ�
        bool merge=(j==i-1);  //���i,j,center���ߣ�Ҳ����merger=false����ô�Ͳ��ܼ������������Σ������ʹj���ڲ�
        while(j)
		{
            int k=j-1;
            //i,j,k����һ���ǣ�ֻ������kj��ki��˳ʱ�뷽����߹��ߣ��ſ��ܹ���͹����Σ��������һ������180�ȵĽ�
            while(k && crossProduct(up[i]-up[k],up[j]-up[k])>0) k--;
            int area=abs(crossProduct(up[i]-center,up[j]-center));  //i,j,center֮�乹�ɵ����������
            //���i,j,k��һ��͹����εĶ��ǣ���ô�Ϳ��Լ����������������j,k���ɵ�͹�����,��һ������Ҫ��k��Լ��ʹ��͹������ڲ�û�е�
            //ͨ��j��k�ĵ���ʹ��������center,i,j��û�е㣬ͬʱcenter,i,k��Ҳû�е�
            if(k) area+=dp[j][k];
            if(merge) dp[i][j]=area;  //��������ߣ��Ϳ��Լ������飬�����´ε���
            ans=max(ans,area);  //�������Ž�
            j=k; //��һ��j��
        }
        if(merge){
            //������center,i,j������е㣬����������оͻᱻ������dp[i][j]=0
            for(int j=2;j<i;++j) dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
}

int main(void){
	freopen("in.txt","r",stdin);

    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            scanf("%d%d",&points[i].x,&points[i].y);
        }
        ans=0;
        for(int i=0;i<m;++i){
            //�������еĵ㣬����ȷ��һ����͵�i������ж����͵㣬��ô�����i������͵��е������ö���
            //���������еĵ㶼�ڵ�i���Ϸ�
            center=points[i];
            d=0;  //��¼���õ������
            for(int j=0;j<m;++j){
                if(points[j].y>points[i].y || (points[j].y==points[i].y && points[j].x>points[i].x))
                    up[++d]=points[j];
            }
            solve();
        }
        printf("%.1lf\n",0.5*ans);
    }
    return 0;
}

