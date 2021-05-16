#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> oset;
 
#define int long long
const int mod = 1e9+7;
 
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
 
void toh(int n , int a , int b , int c){
	if(n > 0){
		toh(n-1,a,c,b);
		cout<<a<<" "<<c<<"\n";
		toh(n-1,b,a,c);
	}
}

 
void test_case(){
   int n;
   cin >> n;
   cout<<(1 << n)-1<<"\n";
   toh(n,1,2,3);
}
 
int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
        while(t--){
            test_case();
        }
        return 0;
}
