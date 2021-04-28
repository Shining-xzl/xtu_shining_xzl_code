#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
using namespace std;

typedef complex<double> CP;
const double Pi = acos(-1);
const int lim = 1<<22;
char s[lim>>1];
CP a[lim],b[lim];
int num[lim];

#define debug(x) printf("%s : %d\n",#x,x);

void FFT(CP *x,int lim,int inv)
{
	int bit = 0,m;
	CP stand,now,temp;
	while((1<<bit) < lim) ++bit;
	for (int i = 0; i < lim; ++i)
	{
		m = 0;
		for (int j = 0; j < bit; j++)
			if((1<<j) & i) m |= (1<<(bit-j-1));
		if(i < m) swap(x[i],x[m]);
	}
	for (int len = 2; len <= lim; len <<= 1)
	{
		stand = CP(cos(2*Pi/len),inv*sin(2*Pi/len));
		m = len >> 1;
		for (CP *p = x; p != x+lim; p += len)
		{
			now = CP(1,0);
			for (int i = 0; i < m; ++i,now *= stand)
			{
				temp = now * p[i+m];
				p[i+m] = p[i] - temp;
				p[i] = p[i] + temp;
			}
		}
	}
}

int init()
{
	scanf("%s",s);
	int len = strlen(s),n,pos = 0;
	for (int i = len-1; i >= 0; --i)
		a[pos++].real(s[i] - '0');
	pos = 0;
	n = len;
	memset(s, 0, sizeof(s));
	scanf("%s",s);
	len = strlen(s);
	for (int i = len-1; i >= 0; --i)
		b[pos++].real(s[i] - '0');
	n += len;
	pos = 1;
	while(pos <= n) pos <<= 1;
	return pos;
}

int main()
{
	int n = init();
	FFT(a,n,1);
	FFT(b,n,1);
	for (int i = 0; i < n; ++i)
		a[i] *= b[i];
	FFT(a,n,-1);
	for (int i = 0; i < n; ++i)
		num[i] = floor(a[i].real()/n+0.5);
	while(num[n] == 0) --n;
	for (int i = 0; i <= n; ++i)
	{
		if (num[i] > 9)
		{
			num[i+1] += num[i]/10;
			num[i] %= 10;
		}
	}
	while(num[n+1] > 0)
	{
		++n;
		if(num[n] > 9)
		{
			num[n+1] = num[n]/10;
			num[n] %= 10;
		}
	}
	for (int i = n; i >= 0; --i)
		putchar(num[i] + '0');
	return 0;
}