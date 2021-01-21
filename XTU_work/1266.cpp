#include <cstdio>
#include <cstring>
using namespace std;
const int T=10003;
char s[T+1];
short R[T+1],G[T+1],B[T+1],len;
int ans;

void find()
{
	int i;
	len=strlen(s);
	R[T]=0;
	G[T]=0;
	B[T]=0;
	for(i=1;i<=len;i++)
	{
		R[i]=R[i-1];
		G[i]=G[i-1];
		B[i]=B[i-1]; 
		if(s[i-1]=='R') R[i]++,R[T]++;
		else if(s[i-1]=='G') G[i]++,G[T]++;
		else if(s[i-1]=='B') B[i]++,B[T]++;
	}
}

void get(short a[],short b[],short c[])
{
	int an=a[T],bn=b[T],cn=c[T],temp=0;
	int a1,b1,c1,a2,c2;
    a1=a[an];
    b1=b[an];
    c1=c[an];
    a2=a[an+bn]-a[an];
    c2=c[an+bn]-c[an];
	temp=b1+c1;
	a2-=b1;
	if(a2>0) c2+=a2;
	temp+=c2;
	if(temp<ans) ans=temp;
}

int main()
{
	while(scanf("%s",&s)==1)
	{
		find();
		ans=1e+9;
		get(R,G,B);
		printf("%d\n",ans);
	}
	return 0;
} 
