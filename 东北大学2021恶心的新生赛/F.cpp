#include <bits/stdc++.h>
using namespace std;
const int LIM=1e5+3;
struct student
{
	string name;
	int ID,G,X;
}s[LIM];
int m,n;
map<string,int> p;
vector<string> v[102];

inline bool cmp(const student &a,const student &b)
{
	return a.name<b.name;
}

void process()
{
	for(int i=0;i<n;i++)
	{
		p[s[i].name]=i;
		v[s[i].G].push_back(s[i].name);
	}
}

void putxx(int x)
{
	if(x==0) putchar('0');
	char s[7];
	int len=0;
	while(x>0)
	{
		s[++len]=x%10+'0';
		x/=10;
	}
	while(len)
		putchar(s[len--]);
}

int main()
{	
//	freopen("in.txt","r",stdin);
	int T,x;
	string name;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>s[i].name>>s[i].G>>s[i].X>>s[i].ID;
	sort(s,s+n,cmp);
	process();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&T);
		if(T==1)
		{
			cin>>name;
			student &kk=s[p[name]];
			putxx(kk.G);
			putchar(' ');
			putxx(kk.ID);
			putchar(' ');
			putxx(kk.X);
			putchar('\n');
//			cout<<<<' '<<kk.ID<<' '<<kk.X<<endl;
		}
		else if(T==2)
		{
			scanf("%d",&x);
			int len=v[x].size();
			for(int i=0;i<len;i++)
			{
				for(int j=0;v[x][i][j]!=0;j++)
					putchar(v[x][i][j]);
				putchar('\n');
			}
//				cout<<v[x][i]<<endl;
		}
	}
	return 0;
} 
