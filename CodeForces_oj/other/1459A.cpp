#include <cstdio>
#include <algorithm>
using namespace std;
int sa[1003],lena,sb[1003],lenb;
int main()
{
//	freopen("in.txt","r",stdin);
	int time,n;
	char a[1003],b[1003];
	int numa0,numb0,na,nb;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&n);
		scanf("%s%s",a,b);
		numa0=numb0=na=nb=0;
		lena=lenb=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='0') numa0++;
			if(b[i]=='0') numb0++;
			if(a[i]>b[i]) na++;
			else if(a[i]<b[i]) nb++;
			if(a[i]!='0'&&b[i]=='0') sa[++lena]=a[i];
			if(b[i]!='0'&&a[i]=='0') sb[++lenb]=b[i];
		}
		if(numa0!=numb0)
		{
			printf("%s\n",numa0>numb0?"BLUE":"RED");
		}
		else
		{
			if(na==nb)
			{
				if(lena>lenb) printf("RED\n");
				else if(lenb>lena) printf("BLUE\n");
				else if(lenb==lena)
				{
					na=nb=0;
					for(int i=1;i<=lena;i++)
						for(int j=1;j<=lenb;j++)
						{
							if(sa[i]>sb[j]) na++;
							if(sa[i]<sb[j]) nb++;
						}
					if(na==nb) printf("EQUAL\n");
					else printf("%s\n",na<nb?"BLUE":"RED");
				}
				else printf("EQUAL\n");
			}
			else if(na>nb)
				printf("RED\n");
			else printf("BLUE\n");
		}
	}
	return 0;
}