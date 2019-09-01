#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 255
#define MAXM 32005
struct Pos
{
    double pos;
    char s[MAXN],dir[4];
    bool operator < (const struct Pos & a)const{
        return pos < a.pos;
    }
}pos[MAXM];
double last[MAXM];
int main()
{
    int n;
    double l,v,len;
    while(scanf("%d",&n),n)
    {
        scanf("%lf%lf",&l,&v);
        double maxn = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%s %lf %s",&pos[i].dir,&pos[i].pos,&pos[i].s);
            if(pos[i].dir[0] == 'p' || pos[i].dir[0] == 'P')
                len = l - pos[i].pos;
            else len = pos[i].pos;
            maxn = max(maxn,len);
        }
        bool zero = false;
        for(int i = 0;i < n;i++)
        {
            if(pos[i].dir[0] == 'p' || pos[i].dir[0] == 'P')
                last[i] = pos[i].pos + maxn;
            else last[i] = pos[i].pos - maxn;
            if(last[i] == 0)zero = true;
        }
        int ind = 0,limit = l;
        if(zero)limit = 0;
        for(int i = 0;i < n;i++)
        {
            if(last[i] < limit)
                ind++;
        }
        printf("%13.2lf %s\n",(int)(maxn / v * 100) / 100.0,pos[ind].s);
    }
}
