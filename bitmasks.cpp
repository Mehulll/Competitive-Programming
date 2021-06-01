for(int i = 0 ; i < (1 << n) ; i++){
  for(int j = 0 ; j < n ; j++){
    if(i & (1 << j)){
      // something 
    }
    else{
      // something
    }
  }
}

struct Solver {
 void solve(){
   int n; cin >> n;
    int ax = 1023 , in = 0;
    for(int i = 0 ; i < n ; i++){
      char x; int num;
      cin >> x >> num;
      if(x == '|'){
        ax |= num;
        in |= num;
      }
      else if(x == '&'){
        ax &= num;
        in &= num;
      }
      else{
        ax ^= num;
        in ^= num;
      }
    }
    int xornum = ~ax;
    int ornum = ~(ax ^ in);
    xornum &= 1023;
    ornum &= 1023;
    cout<<2<<"\n";
    cout<<"| "<<ornum<<"\n";
    cout<<"^ "<<xornum<<"\n";
  }
};

/ -------------------------------------------------------------

// Sum over subset dp 
// For every mask, computes the sum of `values[sub]` where `sub` is a submask of mask.
template<typename T_out, typename T_in>
vector<T_out> submask_sums(int n , const vector<T_in> &values){
  assert(int(values.size()) == 1 << n);
  vector<T_out> dp(values.begin(),values.end());

  // Broken profile DP where the intermediate DP state consists of the ith state consists of the i-th suffix of the previous row and the ith 
  // prefix of the current row.
  for(int i = 0 ; i < n ; i++){
    for(int base = 0 ; base < (1 << n) ; base += 1 << (i+1)){
      for(int mask = base; mask < base + (1 << i) ; mask++){
        dp[mask + (1 << i)] += dp[mask];
      }
    }
  }
  return dp;
}

// For every mask, computes the sum of 'values[sup]' where mask is a submask of 'sup'.
template<typename T_out,typename T_in>
vector<T_out> supermask_sums(int n , vector<T_in> values){
  reverse(values.begin(),values.end());
  vector<T_out> result = submask_sums<T_out>(n,values);
  reverse(result.begin(),result.end());
  return result;
}
/------------------------------------------------------------------------------------------
