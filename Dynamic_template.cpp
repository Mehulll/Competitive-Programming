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
