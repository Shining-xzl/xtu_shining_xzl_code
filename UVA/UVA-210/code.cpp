//队列的运用
//deque双向队列，queue单向队列
#include <cstdio>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

const char LOCK=101;
const char UNLOCK=100;
const char PR=99;

int n;
int t1,t2,t3,t4,t5,Q;
int var_val[28];
bool lock;

struct older
{
	char var;//既指变量也指指令
	int val;
	older(char a,int b):var(a),val(b) {}
};

#define QO queue<older>
vector< QO > q_programs;//程序库
queue< int > qb;
deque< int > qw;

void process(int id)
{
	int time=Q;
	older now(0,0);
	QO &Now=q_programs[id];
	while(time>0&&!Now.empty())//time，倒计时技术
	{
		now=Now.front();
		if(now.var==PR)
			printf("%d: %d\n",id+1,var_val[now.val]),time-=t2;
		else if(now.var==UNLOCK)
		{
			time-=t4;
			lock=0;
			if(!qb.empty())
			{
				qw.push_front(qb.front());
				qb.pop();
			}
		}
		else if(now.var==LOCK)
		{
			time-=t3;
			if(lock)
			{
				qb.push(id);
				return;
			}
			else lock=1;
		}
		else var_val[(int)now.var]=now.val,time-=t1;
		Now.pop();
	}
	if(!Now.empty()) qw.push_back(id);
}

void initail()
{
	memset(var_val,0,sizeof(var_val));
	q_programs.clear();
	while(!qw.empty()) qw.pop_front();
	while(!qb.empty()) qb.pop();
}

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		initail();
		scanf("%d%d%d%d%d%d%d",&n,&t1,&t2,&t3,&t4,&t5,&Q);
		char s[10],x;
		int num;
		for(int i=1;i<=n;++i)
		{
			QO temp;
			while(1)
			{
				scanf("%s",s);
				if(strlen(s)==1)
				{
					scanf(" %*c %d",&num);
					temp.push(older(s[0]-'a',num));
				}
				else if(s[0]=='p')
				{
					scanf(" %c ",&x);
					temp.push(older(PR,x-'a'));
				}
				else if(s[0]=='u')
					temp.push(older(UNLOCK,0));
				else if(s[0]=='l')
					temp.push(older(LOCK,0));
				else break;
			}
			q_programs.push_back(temp);
			qw.push_back(i-1);
		}
		int id;
		while(!qw.empty())
		{
			id=qw.front();
			qw.pop_front();
			process(id);
		}
		if(time) printf("\n");
	}
	return 0;
} 
