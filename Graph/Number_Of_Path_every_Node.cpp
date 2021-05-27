vector<int> npath;
int n;

int dfs_node_path(int u , int p = -1){
	int total_path = n*(n-1)/2;
	int substree_size = 1;
	for(auto x : edges[u]){
		if(x != p){
			int value = dfs_node_path(x,u);
			total_path-=value*(value-1)/2;
		}
	}
	int above = n - substree_size;
	total_path -= above * (above-1)/2;
	npath[u] = total_path;
	return substree_size;
}
