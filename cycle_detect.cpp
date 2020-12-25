const int nax = 2e5+5;
vector<int> edges[nax];
int vis[nax];
vector<int> st , cycle;

void cycle_detect(int u = 0 , int par = -1){
	vis[u] = 1;
	st.push_back(u);
	for(auto x : edges[u]){
		if(!vis[x]){
			cycle_detect(x,u);
		}  
		else if(vis[x] == 1){
			if(x != par){
				cycle.push_back(x);
				int pos = st.size()-1;
				for(int i = pos ; i >= 0 ; i--){
					if(st[i] == x)
						break;
					cycle.push_back(st[i]);
				}
			}
		}
	}
	vis[u] = 2;
	st.pop_back();
}
