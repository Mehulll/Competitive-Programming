 // https://codeforces.com/problemset/problem/321/C

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 2e5 + 5;
const int INF = 1e9+1;
const int mod = 1e9+7;

const int nax = 1e5+5;
set<int> edges[nax];
int sub[nax];
int parent[nax];

int dfs1(int u , int p){
  sub[u] = 1;
  for(auto x : edges[u]){
    if(x != p){
      sub[u] += dfs1(x,u);
    }
  }
  return sub[u];
}
 
int dfs(int u , int p , int l){
  for(auto x : edges[u]){
    if(x != p && sub[x] > l/2)
      return dfs(x,u,l);
  }
  return u;
}
 
void Decompose(int u , int p){
  int subTreeSize = dfs1(u,-1);
  int centroid = dfs(u,p,subTreeSize);
  parent[centroid] = p;
  // cout<<"tree rooted at "<<u<<" with size "<<subTreeSize<<" has centroid "<<centroid<<endl;
  for(auto x : edges[centroid]){
    edges[x].erase(centroid);
    Decompose(x,centroid);
  }
}
 
// --- Decompose ends here ----

int depth[nax]; 

void dfs_depth(int u , int p = -1){
  for(auto x : edges[u]){
    if(x != p){
      depth[x] = depth[u] + 1;
      dfs_depth(x,u);
    }
  }
}

 
int cases  = 0;
struct Solver{
  void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n-1 ; i++){
      int x , y;
      cin >> x >> y;
      x-- , y--;
      edges[x].insert(y);
      edges[y].insert(x);
    }
    Decompose(0,-1);
    int centroid = 0;
    for(int i = 0 ; i < n ; i++){
      if(parent[i] == -1)
        centroid = i;
    }
    for(int i = 0 ; i < n ; i++){
      edges[i].clear();
    }
    for(int i = 0 ; i < n ; i++){
      if(i != centroid){
        edges[i].insert(parent[i]);
        edges[parent[i]].insert(i);
      }
    }
    dfs_depth(centroid);
    for(int i = 0 ; i < n ; i++){
      cout<<char('A'+depth[i])<<" ";
    }
  }
};
 
int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
     int ts = 1;
     // cin >> ts;
    rrep(ti,ts) {
        cases++;
        Solver solver;
        solver.solve();
    }
    return 0;
}
