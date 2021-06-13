bool vis2[nax];

bool cycle(int node , int par){
    	vis2[node] = 1;
    	for(int child : edges[node]){
    		if(!vis2[child]){
    			if(cycle(child,node))
    				return true;
    		}
    		else
    			if(child != par || child == node)
    				return true;
    	}
    	return false;
}
