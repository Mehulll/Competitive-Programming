#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9+7;

int cases = 0;const int nax = 1e5+5;

vector<int> edges[nax];
int in[nax] , low[nax];
bool vis[nax];
int n , m;
int ans = 0;

int timer = 1 , SCC = 0;

void dfs(int u , int p = -1){
  vis[u] = 1;
  in[u] = low[u] = timer++;
  int children = 0;
  for(auto x : edges[u]){
    if(x != p){
      if(vis[x]){
        // edge node - child is a back edge
        low[u] = min(low[u],in[x]);
      }
      else{
        // edge node - child forward
        dfs(x,u);
        low[u] = min(low[u],low[x]);
        if(low[x] >= in[u] && p != -1){
          ans++;
        }
        children++;
      }
    }
  }
  if(p == -1 && children > 1)
    ans++;
}

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
  timer = 0;
  memset(in,-1,sizeof(in));
  memset(low,-1,sizeof(low));
  for(int i = 0 ; i < n ; i++){
    if(!vis[i])
      dfs(i);
  }
  cout<<ans;
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
