#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char s[102];
double A,B;
double K[12][33];

inline bool right(double a,double b)
{
	if(fabs(a-b)<1e-4) return true;
	else return false;
}

inline void get()
{
	int i=0,len=strlen(s);
	double k=10.0;
	A=0.0;
	while(s[i]!='.')
		A=A*10+(double)(s[i++]-48);
	i++;
	while(s[i]!='e')
		A+=double(s[i++]-48)/k,k*=10;
	i++;
	B=0.0;
	while(i<len)
		B=B*10+(double)(s[i++]-48);
}

void prime()
{
	double M=1.000000,E;
	for(short i=0;i<=9;i++)
	{
		M/=2.000000;
		E=1.000000;
		for(short j=1;j<=30;j++)
		{
			E*=2.000000;
			K[i][j]=log10(1.00000-M)+(E-1.000000)*log10(2.000000);
		}
	}
}

inline void out_put()
{
	double I=B+log10(A);
	for(short i=0;i<=9;i++)
		for(short j=1;j<=30;j++)
			if(right(I,K[i][j]))
			{
				printf("%d %d\n",i,j);
				return;
			}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	prime();
	while(scanf("%s",&s)==1)
	{
		if(strlen(s)==3&&s[0]=='0'&&s[1]=='e'&&s[2]=='0') break;
		get();
		out_put();
	}
	return 0;
}
