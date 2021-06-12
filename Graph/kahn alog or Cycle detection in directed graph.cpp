const int nax = 1e5+5;
vector<int> edges[nax];
vector<int> res;
int in[nax];

void kahn(int n){
  queue<int> q;
  for(int i = 0 ; i < n ; i++){
    if(in[i] == 0)
      q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    res.push_back(cur);
    q.pop();
    for(auto x : edges[cur]){
      in[x]--;
      if(in[x] == 0)
        q.push(x);
    }
  }
}

// for cycle check (int)res.size() == n or not
// used in topological sort
