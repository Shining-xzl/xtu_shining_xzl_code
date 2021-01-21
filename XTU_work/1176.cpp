#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string time[18],name[18];
bool k[18];

int main()
{
    int n,b;
    char s[100];
    scanf("%d",&n);
    string timex,namex;
    while(cin>>timex)
    {
        cin>>namex>>b;
        gets(s);
        b-=1000;
        if(s[1]=='A')
        {
            if(!k[b])
            {
                time[b]=timex;
                name[b]=namex;
                k[b]=1;
            }
            else if(timex<time[b])
            {
                time[b]=timex;
                name[b]=namex;
            } 
        }
    }
    for(b=1;b<=n;b++)
    {
        printf("%d",b+1000);
        if(k[b])
        {
            cout<<' '<<time[b]<<' '<<name[b];
        }
        printf("\n");
    }
    return 0;
}
