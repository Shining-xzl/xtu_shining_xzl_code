/*
多项式乘法板子题
FFT -> O(nlogn)
*/
#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

int n,m;
typedef complex<double> CP;
const int lim = 1<<21;
const double Pi = acos(-1);

CP a[lim],b[lim];

void FFT(CP *x,int lim,int inv) // x为多项式数组，lim为长度(必须为2的整次幂)，inv（1/-1）求点值表示，还是系数表示
{
	int bit = 1,m;
	CP stand,now,temp;
	while((1<<bit) < lim) ++bit;
	for (int i = 0; i < lim; ++i) // 蝴蝶变换
	{
		m = 0;
		for (int j = 0; j < bit; ++j)
			if(i & (1<<j)) m |= (1<<(bit-j-1));
		if(i < m) swap(x[m],x[i]);
	}
	for (int len = 2; len <= lim; len <<= 1)//从最底层开始向上归置
	{
		m = len >> 1;
		stand = CP(cos(2*Pi/len),inv*sin(2*Pi/len));//**关键，观察公式，二分关键，单位根
		for (CP *p = x; p != x+lim; p += len)
		{
			now = CP(1,0);
			for (int i = 0; i < m; ++i,now*=stand)
			{
				temp = now * p[i+m];
				p[i+m] = p[i] - temp;
				p[i] = p[i] + temp;
			}
		}
	}
	if(inv == -1) // 求系数表示法，仅当inv = -1时
		for (int i = 0; i < lim; ++i)
			x[i].real(x[i].real()/lim);
}

int main()
{
	double x;
	scanf("%d %d",&n,&m);
	for (int i = 0; i <= n; ++i)
	{
		scanf("%lf",&x);
		a[i].real(x);
	}
	for (int i = 0; i <= m; ++i)
	{
		scanf("%lf",&x);
		b[i].real(x);
	}
	int num = 1;
	while(num <= n+m) num<<=1;
	FFT(a,num,1);
	FFT(b,num,1);
	for (int i = 0; i < num; ++i)
		a[i] *= b[i];
	FFT(a,num,-1);
	for (int i = 0; i <= n+m; ++i)
		printf("%d ", (int)floor(a[i].real()+0.5));
	return 0;
}