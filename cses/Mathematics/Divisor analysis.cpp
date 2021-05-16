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
 
 
void test_case(){
   int n;
   cin >> n;
   map<int,int> l;
   int divisors = 1;
   int sum = 1;
   int product = 1;
   int cnt = 1;
   for(int i = 0 ; i < n ; i++){
    int x , y;
    cin >> x >> y;
    l[x] = y;
    divisors = (divisors*(y+1))%mod;
    sum = (sum*(Sum_OF_DIVISORS(x,y)))%mod;
    product = power(product,y+1,mod) * power(power(x,(y)*(y+1)/2,mod),cnt,mod)%mod;
    cnt = cnt * (y+1)%(mod-1);
   }
   // int p = ((divisors-1)%mod*power(2,mod-2,mod))%mod;
   // product = power(product,p,mod);
 
   cout<<divisors<<" "<<sum<<" "<<product<<" ";
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
