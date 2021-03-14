// sum of two pairs are equal ax + ay = az + aw in an array
#include <bits/stdc++.h>
#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
#define has(x,y) ((x).find(y) != (x).end())

#define int ll
const int mod = 1000000007;

int lcm(int a , int b){
  return (a/__gcd(a,b)*b);
}

// bool is_prime(int n){
//   for(int i = 2 ; i <= sqrt(n) ; i++){
//     if(n%i == 0)
//       return false;
//   }
//   return true;
// }

int dp[2010][2010];

int f(int k , int n){
  if(dp[k][n] != -1)
    return dp[k][n];
  dp[k][n] = 0LL;
  for(int i = 1 ; i <= n ; i++){
    dp[k][n] = (dp[k][n] + f(k-1 , n/i))%mod;
  }
  return dp[k][n];
}

// int n , k;
// vector<int> a;

// bool check(int x , v(int)& a , v(int)& b){
//  int cost = 0;
//  for(int i = 0 ; i < n ; i++){
//   cost += max(0LL,a[i]*x-b[i]);
//   if(cost > k)
//     return false;
// }
//   return true;
// }

// template<typename T>
// struct BIT {
//   int n;
//   vector<T> d;
//   BIT(int n=0):n(n),d(n+1) {}
//   void add(int i, T x=1) {
//     for (i++; i <= n; i += i&-i) {
//       d[i] += x;
//     }
//   }
//   void replace(int i , T v){
//     add(i,v-sum(i,i+1));
//   }
//   T sum(int i) {
//     T x = 0;
//     for (i++; i; i -= i&-i) {
//       x += d[i];
//     }
//     return x;
//   }
//   T sum(int l, int r) {
//     return sum(r-1) - sum(l-1);
//   }
// };

const int nax = (2.5e6)+10;

// bool ok(v(int)& a){
//   rrep(i,sz(a)-1){
//     if(a[i-1] < a[i])
//       return 0;
//   }
//   return 1;
// }

// int s[nax];

struct Solver {
 void solve(){
  int n; cin >> n;
  v(int) a(n);
  rep(i,n) cin >> a[i];
   v(int) seen_1(nax,-1);
   P good_pair(-1,-1);
   vp seen_2(2*nax , P(-1,-1));
   rep(i,n){
    if(seen_1[a[i]] != -1){
      if(good_pair.first != -1){
        cout<<"YES\n";
        cout<<good_pair.first+1<<" "<<i+1<<" "<<good_pair.second+1<<" "<<seen_1[a[i]]+1<<"\n";
        exit(0);
      }
      good_pair = {i,seen_1[a[i]]};
      seen_1[a[i]] = -1;
    }
    for(int j = 0 ; j < i ; j++){
      int s = a[i] + a[j];
      if(seen_2[s].first == -1){
        seen_2[s] = {j,i};
      }
      else{
        int x = seen_2[s].first;
        int y = seen_2[s].second;
        if(x == i || y == j || x == j || y == i){

        }
        else{
          cout<<"YES\n";
          cout<<x+1<<" "<<y+1<<" "<<i+1<<" "<<j+1<<"\n";
          exit(0);
        }
      }
    }
   }
   cout<<"NO\n";
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
    Solver solver;
    solver.solve();
  }
  return 0;
}

