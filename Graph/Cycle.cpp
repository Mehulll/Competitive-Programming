bool vis2[nax];

bool cycle(int node , int par){
	vis2[node] = 1;
	for(int child : edges[node]){
		if(vis2[child] == 0){
			if(cycle(child,node) == true)
				return true;
		}
		else
			if(child != par)
				return true;
	}
	return false;
}
