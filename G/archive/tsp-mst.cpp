#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
#define lcnt (cnt<<1)
#define rcnt (cnt<<1|1)
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        //cout << mb << endl;
        f(mb)?rb=mb:lb=mb+1;
    }
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1;
    }
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class H, class T> void read(pair<H,T>&c);
template<class T> void read(T& x) {cin >> x;}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class T> void read(pair<H,T>&c){read(c.first);read(c.second);}
template<class H, class... T> void read(H& h, T&... t) {read(h);read(t...);}
template<class A> void read(vector<A>& x) {EACH(a, x)read(a);}
template<class A, size_t S> void read(array<A, S>& x) {EACH(a, x)read(a);}
template <class T> string to_string(T v);
template<class T,class U> string to_string(pair<T,U> a);
string to_string(char c) {return string(1, c);}
string to_string(bool b) {return b?"true":"false";}
string to_string(const char* s) {return string(s);}
string to_string(string s) {return s;}
string to_string(vector<bool> v) {
    string res;
    FOR(sz(v))res+=char('0'+v[i]);
    return res;
}
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)res+=char('0'+b[i]);
    return res;
}

template <class T> string to_string(T v) {
    char c=' ';
    if constexpr (std::is_same_v<T, vector<vector<ll>>>) c='\n';
    if constexpr (std::is_same_v<T, vector<vector<int>>>) c='\n';
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)res+=c;
        f=0;
        res+=to_string(x);
    }
    return res;
}
template<class T,class U> string to_string(pair<T,U> a){return to_string(a.first)+":"+to_string(a.second);}
template<class A> void write(A x) {cout << to_string(x);}
template<class H, class... T> void write(const H& h, const T&... t) {write(h);write(t...);}
template<class H, class... T> void print(const H& h, const T&... t);
void print() {write("\n");}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))write(' ');
    print(t...);
}
void DBG() {cout << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
    cout << to_string(h);
    if(sizeof...(t))
        cout << ", ";
    DBG(t...);
}
//#define _DEBUG
#ifdef _DEBUG
#define debug(...) cout << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [\n", DBG(__VA_ARGS__)
#else
#define debug(...) 0
#endif

template<class T> void offset(ll o, T& x) {x+=o;}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)offset(o, a);
}
template<class T, size_t S> void offset(ll o, array<T, S>& x) {
    EACH(a, x)offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<>(a, b)(mt_rng);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n) {v=vt<T>(n, x);}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)vti(a, x, m);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MAXN = 1e3+20;
const int LOGMAXN = 18;
//ll const MOD=998244353;
ll const MOD=1e9+7;
using namespace std;
clock_t timebegin;
int n;
int w[MAXN][MAXN],tour[MAXN],besttour[MAXN],vertex2idx[MAXN];
int dlb2[MAXN],dlb3[MAXN];
const int DLB=0;
int tmptour[MAXN],tmpvertex2idx[MAXN];
ll mindis=0,curdis=0;
int vis[MAXN],timecnt;
double vec[MAXN][2];
pair<int,int> arr[MAXN][MAXN];
ll bitdp[21][220000];
int nextedge[21][220000];

inline bool timecheck(){
    clock_t timeend = clock();
    double elapsed_secs = double(timeend - timebegin) / CLOCKS_PER_SEC;
    return elapsed_secs>=1.98;
}
inline bool timecntcheck(){
    timecnt++;
    if(timecnt>=1e4){
        timecnt=0;
        return timecheck();
    }
    return false;
}
int mincost[MAXN],pre[MAXN];
vector<int>edge[MAXN];
int dfsMSTcnt=0;
void dfsMST(int u,int fa){
    tour[dfsMSTcnt]=u;
    //print('u',u);
    vertex2idx[u]=dfsMSTcnt++;
    for (int v:edge[u]) {
        if(v==fa)continue; 
        dfsMST(v,u);
    }
}
void prim(int epoch){
    memset(vis,0,sizeof(int)*n);
    memset(mincost,0x3f,sizeof(int)*n);
    FOR(n)edge[i].clear();
    mincost[0] = 0;
    while(1){
        int u = -1;
        FOR(n)if(!vis[i] && (u == -1 || mincost[i] < mincost[u]))u = i;
        if(u == -1)break;
        if(u){
            edge[u].push_back(pre[u]);
            edge[pre[u]].push_back(u);
        }
        vis[u] = 1;
        FOR(v,n)if(umin(mincost[v],w[u][v]))pre[v]=u;
    }
    //FOR(n)print(i,edge[i]);
    if(epoch)FOR(n)shuffle(edge[i].begin(),edge[i].end(),std::default_random_engine(epoch));
    dfsMSTcnt=0;
    dfsMST(0,-1);
}


inline int dis(double a0,double a1,double b0,double b1){
    return int(sqrt((a0-a1)*(a0-a1)+(b0-b1)*(b0-b1))+0.5);
}
void dpforsmalldata(){
    memset(bitdp,0x3f,sizeof(bitdp));
    bitdp[0][(1<<n)-1]=0;
    for(int s=(1<<n)-2;s>=0;--s)
        FOR(i,n)FOR(j,n)if(!(s>>j & 1))
                    if(i!=j && ((s==0 && i==0) || (s && (s>>i & 1))) && umin(bitdp[i][s],bitdp[j][s|(1<<j)]+w[i][j])){
                        nextedge[i][s]=j;
                    }
    //print(0,bitdp[0][0]);
    print(0);
    for (int i = 0,u=0,s=0; i < n-1; ++i) {
        int v=nextedge[u][s];
        //print(v,bitdp[u][s],w[u][v]);
        print(v);
        s|=(1<<v);
        u=v;
        //if(i==n-2)print(0,bitdp[u][s],w[u][0]);
    }
}
inline void reversetour(int i,int j){
    for (int k0 = i+1,k1=j; k0<=k1; ++k0,--k1){
        assert(vertex2idx[tour[k0]]==k0);
        assert(vertex2idx[tour[k1]]==k1);
        swap(vertex2idx[tour[k0]],vertex2idx[tour[k1]]);
        swap(tour[k0],tour[k1]);
        assert(vertex2idx[tour[k0]]==k0);
        assert(vertex2idx[tour[k1]]==k1);
    }

}
inline int opt2(int i,int j){
    int a=tour[i],b=tour[(i+1)%n],c=tour[j],d=tour[(j+1)%n];
    int d0=w[a][b]+w[c][d];
    int d1=w[a][c]+w[b][d];
    if(d0>d1){
        if(DLB)dlb2[a]=dlb2[b]=dlb2[c]=dlb2[d]=1;
        reversetour(i,j);
        return d0-d1;
    }
    return 0;
}
inline int opt3(int i,int j,int k){
    int a=tour[i],b=tour[i+1],c=tour[j],d=tour[j+1],e=tour[k],f=tour[(k+1)%n];
    int d0=w[a][b]+w[c][d]+w[e][f];
    int d1=w[a][c]+w[b][d]+w[e][f];
    int d2=w[a][b]+w[c][e]+w[d][f];
    int d3=w[a][d]+w[e][b]+w[c][f];
    int d4=w[f][b]+w[c][d]+w[e][a];
    int d5=w[a][e]+w[d][b]+w[c][f];
    //http://www.cs.ubc.ca/labs/beta/Courses/CPSC532D-05/Slides/tsp-camilo.pdf
    //https://en.wikipedia.org/wiki/3-opt
    if(d0>d1){
        reversetour(i,j);
        if(DLB)dlb3[a]=dlb3[b]=dlb3[c]=dlb3[d]=1;
        return d0-d1;
    }else if(d0>d2){
        reversetour(j,k);
        if(DLB)dlb3[c]=dlb3[d]=dlb3[e]=dlb3[f]=1;
        return d0-d2;
    }else if(d0>d4){
        reversetour(i,k);
        if(DLB)dlb3[a]=dlb3[b]=dlb3[e]=dlb3[f]=1;
        return d0-d4;
    }else if(d0>d3){
        if(DLB)dlb3[a]=dlb3[b]=dlb3[c]=dlb3[d]=dlb3[e]=dlb3[f]=1;
        memcpy(tmptour+i+1,tour+i+1,sizeof(int)*(j+1-(i+1)));
        //memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = j+1; l <= k; ++l) tour[m]=tour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = i+1; l <= j; ++l) tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d3;
    }
    else if(d0>d5){
        if(DLB)dlb3[a]=dlb3[b]=dlb3[c]=dlb3[d]=dlb3[e]=dlb3[f]=1;
        memcpy(tmptour,tour,sizeof(int)*n);
        memcpy(tmpvertex2idx,vertex2idx,sizeof(int)*n);
        int m=i+1;
        for (int l = k; l >= j+1; --l)tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        for (int l = i+1; l <= j; ++l)tour[m]=tmptour[l],vertex2idx[tour[m]]=m,m++;
        return d0-d5;
    }
    return 0;
}
void solve() {
    read(n);
    FOR(n)FOR(j,2)read(vec[i][j]);
    if(DLB)FOR(n)dlb3[i]=dlb2[i]=1;
    FOR(n){
        int k=0;
        FOR(j,n)if(i!=j){
                w[i][j]=dis(vec[i][0],vec[j][0],vec[i][1],vec[j][1]);
                arr[i][k]={w[i][j],j};
                k++;
            }
        //assert(k==n-1);
        sort(arr[i],arr[i]+n-1);
    }
    //FOR(n)FOR(j,n)assert(w[i][j]==w[j][i]);
    if(n<=16){
        dpforsmalldata();
        //print("min",bitdp[0][0]);
        debug(bitdp[0][0]);
        return;
    }
    FOR(q,100000){
        prim(q);
        curdis=0;
        FOR(n)curdis+=w[tour[i]][tour[(i+1)%n]];
        if(q==0){
            mindis=curdis;
            //debug(mindis);
            memcpy(besttour,tour,n*sizeof(int));
        }
//        FOR(n)write(tour[i]," ");
//        print();
        timecnt=0;
        while(1){
            if(timecheck())break;
            int change=0;
            FOR(i,n-1){
                int changei=0;
                int a=tour[i],b=tour[(i+1)%n];
                if(DLB && !dlb2[a])continue;
                for(auto& [acw,c]:arr[a]){
                    if(DLB && !dlb2[c])continue;
                    if(timecntcheck())goto outtwoloop;
                    int j=vertex2idx[c],d=tour[(j+1)%n];
                    if(w[a][b]*2<acw)break;
                    if(i+1>=j || (j+1)%n==i)continue;
                    int delta = opt2(i,j);
                    change+=bool(delta);
                    changei+=bool(delta);
                    curdis-=delta;
                }
                if(!changei)dlb2[a]=0;
            }

            if(n>100){
                FOR(i,n-1){
                    int a=tour[i];
                    for(auto& [acw,c]:arr[a]){
                        int j=vertex2idx[c];
                        if(i+1>=j || (j+1)%n==i)continue;
                        for(auto& [cew,e]:arr[c]){
                            if(timecntcheck())goto outtwoloop;
                            int k=vertex2idx[e];
                            if(j+1>=k || (k+1)%n==i)continue;
                            int delta=opt3(i,j,k);
                            change+=bool(delta);
                            curdis-=delta;
                        }
                    }
                }
            }


            FOR(i,n-1){
                if(DLB && !dlb3[tour[i]])continue;
                int changei=0;
                FOR(j,i+2,n){
                    if(DLB && !dlb3[tour[j]])continue;
                    FOR(k,j+2,n){
                        if(DLB && !dlb3[tour[k]])continue;
                        if(timecntcheck())goto outtwoloop;
                        int delta=opt3(i,j,k);
                        change+=bool(delta);
                        changei+=bool(delta);
                        curdis-=delta;
                    }
                }
                if(!changei)dlb3[tour[i]]=0;
            }
            outtwoloop:;
            if(change==0)break;
            //break;
        }
        if(umin(mindis,curdis))memcpy(besttour,tour,n*sizeof(int));
        //break;
        if(timecheck())break;
    }
    debug(mindis);
    ll finaldis=0;

    FOR(n)finaldis+=w[besttour[i]][besttour[(i+1)%n]];
    assert(mindis==finaldis);
#ifndef _DEBUG
    FOR(n)print(besttour[i]);
#endif
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef _DEBUG
    freopen("/home/csc/Online-Judge-Code/G/1000tsp.txt", "r", stdin);
#endif
    //1000tsp 49295531
    //opt2+2*opt3 = 48689614
    //opt2+opt3 = 48796791

    //100tsp opt3 17375806
    //opt2+2*opt3 = 17206547
    //opt2+opt3 = 17014981
    //50tsp 11514358
    //10tsp 276
    //freopen("/home/csc/Downloads/vivoparc/1.in", "r", stdin);
    //freopen("/home/csc/G/output.txt", "w", stdout);
    timebegin = clock();
    int t=1;
//    read(t);
    FOR(t) {
        //write("Case #", i+1, ": ");
        solve();
    }
    return 0;
}

/*





 * */