#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 20;
const int INF = 1000000000;

struct Edge {
  int from, to;
  ll cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct Dinic {
  int n, m, s, t, removed=0;
  vector<Edge> edges;    // 边数的两倍
  vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
  bool vis[maxn];         // BFS使用
  int d[maxn];           // 从起点到i的距离
  int cur[maxn];        // 当前弧指针

  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, ll cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        //if(removed==1 && (e.from==n+1 || e.from==0 || e.to==0 || e.to==n+1))continue;
        if(removed==1 && (G[x][i]==m-1 || G[x][i]==m-2))continue;
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  ll DFS(int x, ll a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      //if(removed==1 && (e.from==n+1 || e.from==0 || e.to==0 || e.to==n+1))continue;
      if(removed==1 && (G[x][i]==m-1 || G[x][i]==m-2))continue;
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }

  ll Maxflow(int s, int t) {
    this->s = s; this->t = t;
    ll flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  int checkExist(){
    for (int i = 0; i < G[0].size(); ++i) {
      Edge& e = edges[G[0][i]];
      if(e.flow!=e.cap)return 0;
    }
    for (int i = 0; i < G[n+1].size(); ++i) {
      Edge& e = edges[G[0][i]];
      if(e.flow!=e.cap)return 0;
    }
    return 1;
  }
};
Dinic g;

int main(){
  int n,m,s,t;
  cin >> n >> m >> s >>t;
  g.n=n;
  for (int i = 0; i < m; ++i) {
    int u,v,a,b;
    cin >> u >> v >> a >> b;
    g.AddEdge(u, v, b-a);
    if(a > 0){
      g.AddEdge(u, n+1, a);
      g.AddEdge(0, v, a);
    }
  }
  g.AddEdge(t, s, INF);
  g.Maxflow(0,n+1);
  //cout << " max flow " << endl;
  if(g.checkExist()){
    ll ans=g.edges[g.m-2].flow;
    g.removed=1;
    //cout << " max flow " << endl;
    ans -= g.Maxflow(t,s);
    //cout << " max flow " << endl;
    cout << ans << endl;
  }
  else{
    puts("please go home to sleep");
  }
}
