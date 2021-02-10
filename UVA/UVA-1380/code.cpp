#include <cstdio>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int inf=0x3f3f3f3f;
const int lim=203;
int Max_len,len[lim],n;
vector<int> son[lim];
vector<int> relation[lim];
int f[lim],g[lim];
struct temp_pair 
{ 
	int f,g; 
	temp_pair(int a=0,int b=0):f(a),g(b) {}
};

bool get_data()
{
	bool have_data=0;
	for(int i=0;i<lim;i++)
	{
		son[i].clear();
		relation[i].clear();
	}
	int father,son_x,flag1,flag2;
	string temp;
	stringstream now;
	n=0;
	while(cin>>father)
	{
		n=max(n,father);
		if(father==0) break;
		have_data=1;
		while(cin>>temp)
		{
			if(temp=="0") break;
			char rel=temp[temp.length()-1];
			now.clear();
			if(rel=='d'||rel=='u') temp[temp.length()-1]='\0';
			now.str(temp);
			now>>son_x;
			n=max(n,son_x);
			if(rel=='d') flag1=1,flag2=2;
			else if(rel=='u') flag1=2,flag2=1;
			else flag1=flag2=0;
			son[father].push_back(son_x); 
			son[son_x].push_back(father);
			relation[father].push_back(flag1);
			relation[son_x].push_back(flag2);
		}
	}
	return have_data;
}

void get_len(int x)
{
	int &ans=len[x];
	if(ans>0) return;
	for(int i=0;i<son[x].size();i++)
		if(relation[x][i]==1)
		{
			get_len(son[x][i]);
			ans=max(ans,len[son[x][i]]+1);
		}
	Max_len=max(ans,Max_len);
}

inline bool cmp_f(const temp_pair &a,const temp_pair &b) { return a.f<b.f; }
inline bool cmp_g(const temp_pair &a,const temp_pair &b) { return a.g<b.g; }

bool dp(int fa,int now)
{
	int f0=0,g0=0,Max[lim];
	int len=son[now].size(),v,rel;
	vector<temp_pair> library;
	for(int i=0;i<len;i++)
	{
		v=son[now][i];
		if(v==fa) continue;
		rel=relation[now][i];
		dp(now,v);
		if(rel==1) f0=max(f0,f[v]+1);
		else if(rel==2) g0=max(g0,g[v]+1);
		else library.push_back( temp_pair(f[v],g[v]) );
	}
	f[now]=f0;
	g[now]=g0;
	if(g0+f0>Max_len)
	{
		f[now]=g[now]=inf;
		return 0;
	}
	
	if(!library.empty())
	{
		f[now]=g[now]=inf;
		len=library.size(); 
		sort(library.begin(),library.end(),cmp_f);
		Max[len-1]=library[len-1].g;
		for(int i=len-2;i>=0;i--)
			Max[i]=max(Max[i+1],library[i].g);
		for(int i=0;i<=len;i++)
		{
			int ff=f0,gg=g0;
			if(i>0) ff=max(ff,library[i-1].f+1);
			if(i<len) gg=max(gg,Max[i]+1);
			if(ff+gg<=Max_len) 
			{
				f[now]=ff;
				break;
			}
		}
		
		sort(library.begin(),library.end(),cmp_g);
		Max[len-1]=library[len-1].f;
		for(int i=len-2;i>=0;i--)
			Max[i]=max(Max[i+1],library[i].f);
		for(int i=0;i<=len;i++)
		{
			int ff=f0,gg=g0;
			if(i>0) gg=max(gg,library[i-1].g+1);
			if(i<len) ff=max(ff,Max[i]+1);
			if(ff+gg<=Max_len)
			{
				g[now]=gg;
				break;
			}
		}
	}
//	printf("%d -> %d\n",now,f[now]);
	return f[now]<inf;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	while(get_data())
	{
		memset(len,0,sizeof(len));
		Max_len=0;
		for(int i=1;i<=n;i++) get_len(i);
		if(dp(-1,1)) cout<<Max_len+1<<endl;
		else cout<<Max_len+2<<endl;
	}
	return 0;
} 
