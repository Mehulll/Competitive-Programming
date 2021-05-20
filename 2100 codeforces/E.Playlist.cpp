#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> oset;
 
#define int long long
const int mod = 1e9+7;
const int MOD = 998244353;
 
long double power(long double a,int b){
    long double result=1;
    while(b>0)
    {
        if(b % 2 ==1)
            result=(result * a);
        a=(a*a);
        b=b/2;
    }
    return result;
}
 
// int Sum_OF_DIVISORS(int x , int y){
//     int l = power(x,y+1,mod)-1;
//     if(l < 0)
//         l+=mod;
//     int q = power(x-1,mod-2,mod);
//     l = (l*q)%mod;
//     return l;
// }
 
void greyCode(int n){
	for(int i = 0 ; i < (1 << n) ; i++){
		int val = (i ^ (i >> 1));
		bitset<32> r(val);
		string s = r.to_string();
		cout<<s.substr(32-n)<<"\n";
	}
}


// long double n , m;
// p[i] * l[i] / (1 - l[i])
bool comp(pair<int,int> &a , pair<int,int>& b){
	return a.first*a.second*(100-b.first) > b.first*b.second*(100-a.first);
}

void test_case(){
	int n;
	cin >> n;
	vector<pair<int,int>> l;
	for(int i = 0 ; i < n ; i++){
		int t , p;
		cin >> t >> p;
		l.push_back({p,t});
	}
	sort(l.begin(),l.end(),comp);
	long double ans = 0;
	long double k = 0;
	for(int i = 0 ; i < n ; i++){
		ans += l[i].second;
		ans += k * (100 - l[i].first) / (double)100;
		k += l[i].second * l[i].first / (double)100;
	}
	cout<<ans<<"\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cout<<fixed<<setprecision(20);
    // cin >> t
    while(t--){
        test_case();
    }
    return 0;
}


// total cards = m*n;
// choose n cards from them (m*n choose n)
// 
// 2 2 
// tc = 4
// (4 choose 2) = 6/

