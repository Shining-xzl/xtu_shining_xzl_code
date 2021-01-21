#include <cstdio>
#include <cstring>
using namespace std;

double w[4]={12.01,1.008,16.00,14.01};

void initial()
{
	double ans=0.0,temp;
	int l;
	char s[83];
	scanf("%s",s);
	short len=strlen(s),i;
	for(i=0;i<len;i++)
	{
		l=0;
		temp=0.0;
		if(s[i]=='C') temp=w[0];
		else if(s[i]=='H') temp=w[1];
		else if(s[i]=='O') temp=w[2];
		else if(s[i]=='N') temp=w[3];
		if(s[i+1]<'0'||s[i+1]>'9') l=1;
		while(s[i+1]>='0'&&s[i+1]<='9')
		{
			i++;
			l=(l<<3)+(l<<1)+s[i]-'0';
		}
		ans+=temp*(double)l;
	}
	printf("%.3lf\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
