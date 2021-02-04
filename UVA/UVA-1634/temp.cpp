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
}points[maxn],center,up[maxn];  //center是每次选定的一个,它构成凸多边形的最下方的顶点（之一），uprig是center上方顶点

int distant(const Point &a){
    return a.x*a.x+a.y*a.y;
}
//计算向量叉乘，叉乘是向量构成的平行四边形面积，乘以0.5就是三角形面积
//叉乘的值>0，b在a的逆时针方向，<0,是顺时针,=0三点共线
int crossProduct(const Point &a,const Point &b){
    return a.x*b.y-b.x*a.y;
}

bool Point::operator < (const Point &rhs) const {
    int t=crossProduct(*this-center,rhs-center);
    if(t!=0) return t>0;  //center的上方顶点按照逆时针顺序排列
    return distant(*this-center)<distant(rhs-center);  //i，j，center三点共线，按照距离排序，和center近的在前面
}

void solve(){

    //dp[i][j]是(center，i)为一条边，和j或者序号比j小的点构成的最大的凸多边形面积
    memset(dp,0,sizeof(dp));
    //将上方的点按照逆时针顺序排列，就是（points[k]-center）向量和x轴正方向的角度小的在前面，角度相同的距离近的在前面
    sort(up+1,up+1+d);
    for(int i=1;i<=d;i++)
    {
    	printf("%d %d\n",up[i].x-center.x,up[i].y-center.y);
	}
	printf("*****\n");
    //凸多边形中，最低点顺时针旋转后的第一个顶点
    for(int i=2;i<=d;++i){
        int j=i-1; //j是i顺时针旋转后的第一个顶点（i,j,center三点不能共线，共线就不是一个三角形了），i,j,center构成一个三角形
        while(j && (!crossProduct(up[i]-center,up[j]-center))) j--;  //如果i,j,center三点共线，寻找下一个合格的点
        bool merge=(j==i-1);  //如果i,j,center共线，也就是merger=false，那么就不能继续叠加三角形，否则会使j在内部
        while(j)
		{
            int k=j-1;
            //i,j,k构成一个角，只有向量kj在ki的顺时针方向或者共线，才可能构成凸多边形，否则或有一个大于180度的角
            while(k && crossProduct(up[i]-up[k],up[j]-up[k])>0) k--;
            int area=abs(crossProduct(up[i]-center,up[j]-center));  //i,j,center之间构成的三角形面积
            //如果i,j,k是一个凸多边形的顶角，那么就可以继续向三角形上添加j,k构成的凸多边形,这一步很重要，k的约束使得凸多边形内部没有点
            //通过j，k的迭代使得三角形center,i,j中没有点，同时center,i,k中也没有点
            if(k) area+=dp[j][k];
            if(merge) dp[i][j]=area;  //如果不共线，就可以计入数组，方便下次叠加
            ans=max(ans,area);  //更新最优解
            j=k; //下一个j点
        }
        if(merge){
            //三角形center,i,j中如果有点，在上面过程中就会被跳过，dp[i][j]=0
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
            //遍历所有的点，首先确定一个最低点i，如果有多个最低点，那么这个点i就是最低点中的最左变得顶点
            //这样就所有的点都在点i的上方
            center=points[i];
            d=0;  //记录可用点的数量
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

