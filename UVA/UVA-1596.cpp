#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const string EOR="zzzzz";
map< string,string > name;
map< string,string > value;

bool check(string x)
{
	for(int i=0;x[i]!='\0';i++)
		if(x[i]<'0'||x[i]>'9')
			return false;
	return true;
}

bool cmp(const string a,const string b)
{
	int x=0,y=0;
	int i=0;
	while(a[i]!='\0')
	{
		x=x*10+a[i]-48;
		i++;
	}
	i=0;
	while(b[i]!='\0')
	{
		y=y*10+b[i]-48;
		i++;
	}
	return x<y;
}

string get_xx(string x)
{
	// cout<<x<<endl;
	int a_pos,b_pos,len;
	string vn,an;
	if(check(x)) return x;
	a_pos=x.find('[');
	b_pos=x.find_last_of(']');
	len=b_pos-a_pos-1;
	an=x.substr(0,a_pos);
	if(name.count(an)==0) return EOR;
	vn=x.substr(a_pos+1,len);
	vn=get_xx(vn);
	x=an+'['+vn+']';
	// cout<<an<<' '<<vn<<' '<<value.count(x)<<' '<<value[x]<<endl;
	// cout<<x<<endl;
	if(!value.count(x)) return EOR;
	else return value[x];
}

bool process(string x)
{
	int a_pos,b_pos,len;
	string an,vn,bn;
	a_pos=x.find('[');
	b_pos=x.find('=');
	if(b_pos==x.npos)
	{
		b_pos=x.find_last_of(']');
		len=b_pos-a_pos-1;
		an=x.substr(0,a_pos);
		vn=x.substr(a_pos+1,len);
		vn=get_xx(vn);
		if(vn==EOR) return false;
		name[an]=vn;
		// cout<<an<<' '<<vn<<endl;
	}
	else
	{	
		an=x.substr(0,a_pos);
		if(!name.count(an)) 
			return false;
		vn=x.substr(b_pos+1);
		vn=get_xx(vn);
		if(vn==EOR) 
			return false;
		len=b_pos-a_pos-2;
		bn=x.substr(a_pos+1,len);
		bn=get_xx(bn);				
		if(bn==EOR) 
			return false;
		// cout<<an<<' '<<bn<<endl;
		if(!cmp(bn,name[an]))
			return false;
		// cout<<an+'['+bn+']'<<"**"<<vn<<endl;
		value[an+'['+bn+']']=vn;
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	string x;
	int ans,now;
	while((cin>>x)&&x!=".")
	{
		ans=0;
		now=0;
		name.clear();
		value.clear();
		// printf("**********\n");
		do
		{	
			now++;
			if(!ans)
				if(!process(x))
					ans=now;
			cin>>x;
		}while(x!=".");
		cout<<ans<<endl;
	}
	return 0;
}