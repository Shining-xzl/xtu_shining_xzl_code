#include <cstdio>
#include <cstring>

using namespace std;
const int INF=100003;
int n;
int s[INF],b[INF];
bool k[INF];

inline void sort(int l,int r)
{
	if(l==r) return;
	int i=l,j=r,mid=b[(l+r)>>1],temp;
	while(i<=j)
	{
		while(b[i]<mid) i++;
		while(b[j]>mid) j--;
		if(i<=j)
		{
			temp=b[i];
			b[i]=b[j];
			b[j]=temp;
			i++;
			j--;
		}
	}
	if(i<r) sort(i,r);
	if(l<j) sort(l,j);
}

void initial()
{
	int min=1e+9;
	bool flag;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]<min) min=s[i];
	}
	memset(k,0,sizeof(k));
	for(int i=1;i<=n;i++)
		if(!(s[i]%min)) k[i]=1;
	memcpy(b,s,sizeof(int)*(n+1));
	sort(1,n);
	flag=1;
	for(int i=1;i<=n;i++)
		if((!k[i])&&s[i]!=b[i])
		{
			flag=0;break;
		}
	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--) initial();
	return 0;
}
