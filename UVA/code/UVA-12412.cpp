#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const char *head="Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n";
const char *add="Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
const char *rankp="Showing the ranklist hurts students' self-esteem. Don't do that.\n";
const char *duplicated="Duplicated SID.\n";
const char *r_q="Please enter SID or name. Enter 0 to finish.\n";
const char *showing="Please enter class ID, 0 for the whole statistics.\n";
const char *sbject[4]={"Chinese","Mathematics","English","Programming"};

struct student
{
	string name;
	string id;
	int score[6],cid;
	double v;
};
int ind[103],rankx[103];
vector<student> school;

bool cmp(const int &a,const int &b)
{
	return school[a].score[4]>school[b].score[4];
}

int find_x(string &x,int op)
{
	int len=school.size();
	for(int i=op;i<len;i++)
		if(school[i].id==x||school[i].name==x)
			return i;
	return -1;
}

void add_x()
{
	string temp;
	student now;
	while(1)
	{	
		printf("%s",add);
		cin>>temp;
		if(temp=="0") break;
		now.id=temp;
		cin>>now.cid>>now.name;
		now.score[4]=0;
		for(int i=0;i<4;i++)
			cin>>now.score[i],now.score[4]+=now.score[i];
		now.v=now.score[4]*1.0/4;
		if(find_x(temp,0)!=-1)
			printf("%s",duplicated);
		else school.push_back(now);
	}
}

void remove()
{
	string temp;
	int num,now;
	while(1)
	{
		printf("%s",r_q);
		num=0;
		cin>>temp;
		if(temp=="0") break;
		now=find_x(temp,0);
		while(now!=-1)
		{
			num++;
			school.erase(school.begin()+now);
			now=find_x(temp,now);
		}
		printf("%d student(s) removed.\n",num);
	}
}

void show()
{
	printf("%s",showing);
	int n,pass_k[5]={0},len=school.size(),pass[5]={0},con,num_class=0;
	double all_s[5]={0.0};
	scanf("%d",&n);
	for(int i=0;i<len;i++)
	{
		if(n!=0&&n!=school[i].cid) continue;
		num_class++;
		con=0;
		for(int j=0;j<4;j++)
		{
			all_s[j]+=(double)school[i].score[j];
			if(school[i].score[j]>=60) 
			{
				con++;
				pass[j]++;
			}
		}
		pass_k[con]++;
	}
	for(int j=0;j<4;j++)
	{	
		all_s[j]+=1e-6;
		if(num_class!=0)
			all_s[j]/=num_class;

		printf("%s\n",sbject[j]);
		printf("Average Score: %.2lf\n",all_s[j]);
		printf("Number of passed students: %d\n",pass[j]);
		printf("Number of failed students: %d\n\n",num_class-pass[j]);
	}
	for(int j=3;j>=1;j--)
	 	pass_k[j]+=pass_k[j+1];
	printf("Overall:\n");
	printf("Number of students who passed all subjects: %d\n",pass_k[4]);
	printf("Number of students who passed 3 or more subjects: %d\n",pass_k[3]);
	printf("Number of students who passed 2 or more subjects: %d\n",pass_k[2]);
	printf("Number of students who passed 1 or more subjects: %d\n",pass_k[1]);
	printf("Number of students who failed all subjects: %d\n\n",pass_k[0]);
}

void process()
{
	int len=school.size();
	for(int i=0;i<len;i++)
		ind[i]=i;
	sort(ind,ind+len,cmp);
	for(int i=0;i<len;i++)
		rankx[ind[i]]=i+1;
	for(int i=1;i<len;i++)
		if(school[ind[i]].score[4]==school[ind[i-1]].score[4])
			rankx[ind[i]]=rankx[ind[i-1]];
}

void query()
{
	string temp;
	int now;
	process();
	while(1)
	{
		printf("%s",r_q);
		cin>>temp;
		if(temp=="0") break;
		now=find_x(temp,0);
		while(now!=-1)
		{
			cout<<rankx[now]<<' '<<school[now].id<<' '<<school[now].cid<<' '<<school[now].name<<' ';
			for(int i=0;i<5;i++)
				printf("%d ",school[now].score[i]);
			printf("%.2lf\n",school[now].v);
			now=find_x(temp,now+1);
		}
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int order;
	while(1)
	{
		printf("%s",head);
		scanf("%d",&order);
		if(order==0) break;
		else if(order==1) add_x();
		else if(order==2) remove();
		else if(order==3) query();
		else if(order==4) printf("%s",rankp);
		else if(order==5) show();
	}
	return 0;
}
