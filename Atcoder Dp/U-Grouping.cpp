int n;
int cache[(1 << 17)]; // initialize
vector<vector<int>> a;
int dp(int mask){
  int &ans = cache[mask];
  if(ans != -LINF)
    return ans;
  ans = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
      if((mask & (1 << i)) && (mask & (1 << j)))
      ans+=a[i][j];
    }
  }
  for(int i = mask&(mask-1); i > 0 ; i = (i-1) & mask){
    ans = max(ans,dp(i) + dp(mask ^ i));
  }
  return ans;
}

struct Solver {
 void solve(){
   cin >> n;
   for(int i = 0 ; i <= (1 << n) ; i++)
    cache[i] = -LINF;
   a.resize(n,vector<int>(n));
   for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      cin >> a[i][j];
    }
   }
   cout<<dp((1 << n)-1);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(10);
  int ts = 1;
  // cin >> ts;
  rrep(ti,ts) {
    cases++;
    Solver solver;
    solver.solve();
  }
  return 0;
}
