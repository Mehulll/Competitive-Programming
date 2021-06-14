#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int mod = 1e9+7;
const int nax = 1e5+5;

vector<int> edges[nax] , st;
int in[nax] , low[nax];
bool vis[nax] , active[nax];
int n , m;

int timer = 1 , SCC = 0;

void dfs(int u){
  vis[u] = 1;
  in[u] = low[u] = timer++;
  active[u] = 1;
  st.push_back(u);
  for(auto x : edges[u]){
    if(vis[x] && active[x]){
      low[u] = min(low[u],in[x]);
    }
    else if(!vis[x]){
      dfs(x);
      if(active[x]){
        low[u] = min(low[u],low[x]);
      }
    }
  }

  if(in[u] == low[u]){
    SCC++;
    cout<<"SCC #"<<SCC<<"\n";

    int x;
    while(true){
      x = st.back();
      st.pop_back();
      active[x] = false;
      cout<<x+1<<" ";
      if(x == u)
        break;
    }
    cout<<"\n";
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
  }

  for(int i = 0 ; i < n ; i++){
    if(!vis[i])
      dfs(i);
  }
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
