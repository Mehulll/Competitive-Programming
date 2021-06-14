#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9+7;
const int nax = 1e5+5;

vector<int> edges[nax];
int in[nax] , low[nax];
bool vis[nax];
int n , m;
vector<pair<int,int>> bridges;

int timer = 1 , SCC = 0;

void dfs(int u , int p = -1){
  vis[u] = 1;
  in[u] = low[u] = timer++;

  for(auto x : edges[u]){
    if(x != p){
      if(vis[x]){
        // edge node - child is a back edge
        low[u] = min(low[u],in[x]);
      }
      else{
        // edge node - child forward
        dfs(x,u);
        if(low[x]  > in[u]){
          bridges.push_back({u,x});
          // cout<<u+1<<" - "<<x+1<<" is a bridge\n";
        }
        low[u] = min(low[u],low[x]);
      }
    }
  }
}

int cases = 0;
void test_case() {
  cin >> n >> m;
  for(int i = 0 ; i <= n ; i++){
    edges[i].clear();
    vis[i] = 0;
  }

  for(int i = 0 ; i < m ; i++){
    int a , b;
    cin >> a >> b;
    a-- , b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(0,-1);
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(10);
  int T = 1;
  // cin >> T;
  while(T--){
    cases++;
    test_case();
  }
}
