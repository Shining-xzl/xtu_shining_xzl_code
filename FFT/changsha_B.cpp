/*
思维+FFT模板题
将数字映射成指数，个数映射成系数，秒变多项式乘法
*/
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstring>
#include <iostream>
using namespace std;

typedef complex<double> CP;
/*
	x.real()实部
	x.imag()虚部
*/
#define Max(x,y) ((x)>(y)?(x):(y))
#define debug(x) printf("%s : %d\n",#x,x);

const int lim = 1<<18;
const double Pi = acos(-1);
bool not_prime[lim];
int prime[lim],len = 0;
CP a[lim],b[lim];
int n,m;

void get_prime()
{
	not_prime[0] = not_prime[1] = 1;
	for (int i = 2; i < lim; ++i)
	{
		if (!not_prime[i])
			prime[len++] = i;
		for (int j = 0; j < len && prime[j] * i < lim; ++j)
		{
			not_prime[prime[j]*i] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int init()
{
	for (int i = 0; i < lim; ++i)
	{
		a[i].real(0.0); a[i].imag(0.0);
		b[i].real(0.0); b[i].imag(0.0);
	}
	int x,Ma1 = 0,Ma2 = 0;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		a[x].real(a[x].real()+1.0);
		Ma1 = Max(x,Ma1);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &x);
		b[x].real(b[x].real()+1.0);
		Ma2 = Max(x,Ma2);
	}
	return Ma1+Ma2;
}


void FFT(CP *x,int n,double inv)
{
	int bit = 0,t;
	while((1<<bit) < n) ++bit;
	for (int i = 0; i < n; ++i)
	{
		t = 0;
		for (int j = 0; j < bit; ++j)
			if(i & (1<<j)) t |= (1 << (bit-j-1));
		if (i < t) swap(x[i],x[t]);
	}
	CP stand,now,a;
	for (int len = 2; len <= n; len <<= 1)
	{
		stand = CP( cos(2*Pi/len),inv*sin(2*Pi/len) );
		t = (len >> 1);
		for (CP *p = x; p != x+n; p += len)
		{
			now = CP(1.0,0);
			for (int i = 0; i < t; ++i,now *= stand)
			{
				a = now * p[i+t];
				p[i+t] = p[i] - a;
				p[i] = p[i] + a;
			}
		}
	}
}

int main()
{
	get_prime();
	int T;
	long long ans;
	scanf("%d",&T);
	while(T--)
	{
		m = init();
		n = 1;
		while(n <= m) (n<<=1);
		FFT(a,n,1);
		FFT(b,n,1);
		for (int i = 0; i < n; ++i)
			a[i] *= b[i];
		FFT(a,n,-1);
		ans = 0;
		for (int i = 0; i < n; ++i)
			if(not_prime[i] == 0)
				ans += floor(a[i].real() / n + 0.5);
		printf("%lld\n", ans);
	}
	return 0;
}