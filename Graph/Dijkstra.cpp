vector<pair<int,pair<int,int>>> edges[nax];
int parent[nax];
int dist[nax];
int degree[nax];
int n , k;
int vis[nax];

void diameter(int u){
	vis[u] = 1;
	for(auto x : edges[u]){
		if(!vis[x]){
			dist[x] = dist[u] + 1;
			diameter(x);
		}
	}
}

void test_case() {
	int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
      int x , y , c , d;
      cin >> x >> y >> c >> d;
      x-- , y-- ;
      edges[x].push_back({y,{c,d}});
      edges[y].push_back({x,{c,d}});
    }
    for(int i = 0 ; i <= n ; i++)
      dist[i] = INF;
    // source = 0
    dist[0] = 0;
    // dist , node
    set<pair<int,int>> s;
    s.insert({0,0});
    while(!s.empty()){
      int dis = s.begin()->first;
      int ver = s.begin()->second;
      s.erase(s.begin());
      for(pair<int,pair<int,int>> x : edges[ver]){
        int newdis = x.second.first + (x.second.second/(dis+1));
        int newver = x.first;
        if(dis + newdis < dist[newver]){
          s.erase({dist[newver],newver});
          dist[newver] = newdis + dis;
          s.insert({dist[newver],newver});
        }
      }
    }  
    if(dist[n-1] == INF)
      cout<<"-1\n";
    else
      cout<<dist[n-1]<<"\n";
}
