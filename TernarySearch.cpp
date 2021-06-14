// Atcoder Regular B - Insurance
void solve(){
    int n;
   cin >> n;
   v(int) a(n);
   rep(i,n) cin >> a[i];
   long double low = 0 , high = (*max_element(rng(a)));
   long double ans = 1e18;
   while(high-low > eps){
    long double mid1 = low + (high-low)/3;
    long double mid2 = high - (high-low)/3;
    long double val1 = 0;
    long double val2 = 0;

    for(int i = 0 ; i < n ; i++){
      val1 += mid1 + a[i]-min((long double)a[i],2*mid1);
    }
    for(int i = 0 ; i < n ; i++){
      val2 += mid2 + a[i]-min((long double)a[i],2*mid2);
    }
    val1 = val1/n;
    val2 = val2/n;
    if(val1 < val2){
      ans = min(ans,val1);
      high = mid2;
    }
    else if(val1 > val2){
      ans = min(ans,val2);
      low = mid1;
    }
    if(val1 == val2)
      break;
   }
   cout<<ans<<" ";
  }   
