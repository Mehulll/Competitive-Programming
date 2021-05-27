int dfs_edge_path(int u , int p = -1){
	int substree_size = 1;
	for(auto x : edges[u]){
		if(x != p){
			substree_size+=dfs_edge_path(x,u);
		}
	}
	int above = n - substree_size;
	int total = above * substree_size;
	if(u > 0){
		npath[u-1] = total;
	}
	return substree_size;
}
