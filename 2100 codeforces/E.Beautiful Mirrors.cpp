#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> oset;
 
#define int long long
const int mod = 1e9+7;
const int MOD = 998244353;
 
int power(int a,int b,int M){
    int result=1;
    while(b>0)
    {
        if(b % 2 ==1)
            result=(result * a)%M;
        a=(a*a)%M;
        b=b/2;
    }
    return result%mod;
}
 
int Sum_OF_DIVISORS(int x , int y){
    int l = power(x,y+1,mod)-1;
    if(l < 0)
        l+=mod;
    int q = power(x-1,mod-2,mod);
    l = (l*q)%mod;
    return l;
}
 
void greyCode(int n){
	for(int i = 0 ; i < (1 << n) ; i++){
		int val = (i ^ (i >> 1));
		bitset<32> r(val);
		string s = r.to_string();
		cout<<s.substr(32-n)<<"\n";
	}
}

void test_case(){
	int n;
	cin >> n;
	vector<int> prob(n);
	for(int i = 0 ; i < n ; i++){
		cin >> prob[i];
		prob[i] = (prob[i] * power(100,MOD-2,MOD))%MOD;
		// converting probability in p/100 form
	}
	vector<int> prob_inv(n) , pref(n);
	for(int i = 0 ; i < n ; i++){
		prob_inv[i] = power(prob[i],MOD-2,MOD);
		// calculation all inverse of probability
	}
	pref[0] = 1;
	for(int i = 1 ; i < n ; i++){
		pref[i] = (pref[i-1] * prob[i-1])%MOD;
		// all pref multiplication
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		ans = (ans + pref[i])%MOD;
		// getting the numerator
	}
	for(int i = 0 ; i < n ; i++){
		ans = (ans*prob_inv[i])%MOD;
		// getting the denominator but in inverse
	}
	cout<<ans<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t
    while(t--){
        test_case();
    }
    return 0;
}


// ei = 1 + pi.e(i+1) + (1-pi)e1
// e1 = 1 + p1 * e2 + (1-p1)e1
//...
// en = 1+pn * e(n+1) + (1-pn)e1

// Ans 
// e1 = (1 + p1 + p1*p2 + p1*p2*p3 + ... + p1...p(n-1))/(p1*p2*p3...*pn)
