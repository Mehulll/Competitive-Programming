const int nax = 55; // constant
ll n , a;
ll cache[nax][2*nax*nax]; // memoization
ll l[nax]; // values to be stored

ll dp(ll idx , ll sum){ // states here first find states always
	if(idx == n+1)
		return (sum == 0);
	ll &ans = cache[idx][sum+nax*nax];
	if(ans != -1)
		return ans;
	ans = dp(idx+1,sum)+dp(idx+1,sum+l[idx]); // calculation changes made here
	return ans;
}

void test_case() {
	memset(cache,-1,sizeof(cache)); // memset to  -1 imp
	cin >> n >> a;
	for(int i = 1 ; i <= n ; i++){
		cin >> l[i];
		l[i] -= a;
	}
	ll ans = dp(1,0)-1;  // get ans here 
	cout<<ans<<"\n";
}

// two template

const int nax1 = 1e3+5;

int cache[nax1][nax1][2];
int n , k;
int dp(int a , int b , int taken){
  if(a == 0 || a == n+1 || b == 0){
    if(b > 0)
      return 1;
    return 0;
  }
  int &ans = cache[a][b][taken];
  if(ans != -1)
    return ans;
  ans = 0;
  if(taken == 0){
    ans = dp(a+1,b,0) + dp(a-1,b-1,1);
  }
  else{
    ans = dp(a+1,b-1,0) + dp(a-1,b,1);
  }
  ans %= mod;
  return ans;
}

struct Solver {
 void solve(){
   cin >> n >> k;
   for(int i = 0 ; i <= n ; i++){
    for(int j = 0 ; j <= k ; j++){
      cache[i][j][0] = -1;
      cache[i][j][1] = -1;
    }
   }
   cout<<dp(1,k,0)<<"\n";
  }
};
