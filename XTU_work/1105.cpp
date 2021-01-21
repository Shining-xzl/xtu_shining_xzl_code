#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int time,a,b,c,d,A,B,K;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a*=d;
		c*=b;
		b*=d;
		A=a+c;
		B=b;
		K=gcd(A,B);
		A/=K;
		B/=K;
		printf("%d",A);
		if(B!=1) printf("/%d",B);
		printf(" ");
		A=a-c;
		B=b;
		K=gcd(A,B);
		A/=K;
		B/=K;
		if(B<0) 
		{
			A=-A;
			B=-B;
		}
		printf("%d",A);
		if(B!=1) printf("/%d",B);
		printf("\n");
	}
	return 0;
}
