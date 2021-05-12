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

int lcm(int a , int b){
  return (a/__gcd(a,b)*b);
}

bool is_prime(int n){
  for(int i = 2 ; i <= sqrt(n) ; i++){
    if(n%i == 0)
      return false;
  }
  return true;
}

const int dx[4] = {1,0,-1,0} , dy[4] = {0,1,0,-1};

int cases = 0;

bool compare(pair<vector<int>,int> &a, pair<vector<int>,int> &b){
  return a.first.size() < b.first.size();
}

int countDivisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else  
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

bool divisorsSame(int n){
  return (n-2)%4 == 0;
}

int power(int x,int n,int M)
{   if(n < 0)
      return 0;
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

int getSum(int l){
    int sum = 0;
   while(l){
      sum += l;
      l/=10;
    }
    return sum;
}

const int mod = 1e9+7;


int getnum1(int n){
  return 2*(n*n);
}

int getnum2(int n){
  return (2*n)*(2*n);
}

// int n;
// int cache[(1 << 17)]; // initialize
// vector<vector<int>> a;
// int dp(int mask){
//   int &ans = cache[mask];
//   if(ans != -LINF)
//     return ans;
//   ans = 0;
//   for(int i = 0 ; i < n ; i++){
//     for(int j = i+1 ; j < n ; j++){
//       if((mask & (1 << i)) && (mask & (1 << j)))
//       ans+=a[i][j];
//     }
//   }
//   for(int i = mask&(mask-1); i > 0 ; i = (i-1) & mask){
//     ans = max(ans,dp(i) + dp(mask ^ i));
//   }
//   return ans;
// }

//const int mod = 1000000007;
 //const int mod = 998244353;
 struct mint {
   ll x; // typedef long long ll;
   mint(ll x=0):x((x%mod+mod)%mod){}
   mint operator-() const { return mint(-x);}
   mint& operator+=(const mint a) {
     if ((x += a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator-=(const mint a) {
     if ((x += mod-a.x) >= mod) x -= mod;
     return *this;
   }
   mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
   mint operator+(const mint a) const { return mint(*this) += a;}
   mint operator-(const mint a) const { return mint(*this) -= a;}
   mint operator*(const mint a) const { return mint(*this) *= a;}
   mint pow(ll t) const {
     if (!t) return 1;
     mint a = pow(t>>1);
     a *= a;
     if (t&1) a *= *this;
     return a;
   }
 
   // for prime mod
   mint inv() const { return pow(mod-2);}
   mint& operator/=(const mint a) { return *this *= a.inv();}
   mint operator/(const mint a) const { return mint(*this) /= a;}
 };
 istream& operator>>(istream& is, mint& a) { return is >> a.x;}
 ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
}c(2e6+5);

mint formula(int x1 , int y1 , int x2 , int y2){
	if(x1 > x2)
		return 0;
	if(y1 > y2)
		return 0;
	mint k = c(x2-x1+y2-y1,x2-x1);
	return k;
}

struct Solver {
 void solve(){
	 int h,w , m;
	cin >> h >> w >> m;
	vector<pair<int,int>> a(m);
	for(int i = 0 ; i < m ; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(),a.end());
	vector<mint> reach(m);
	reach[0] = formula(1,1,a[0].first,a[0].second);
	for(int i = 1 ; i < m ; i++){
		mint subtract = 0;
		reach[i] = formula(1,1,a[i].first,a[i].second);
		for(int j = 0 ; j < i ; j++)
			subtract += reach[j] * formula(a[j].first,a[j].second,a[i].first,a[i].second);
		reach[i]-=subtract;
	}
	mint ans = c(h+w-1-1,h-1);
	for(int i = 0 ; i < m ; i++)
		ans-=reach[i]* formula(a[i].first,a[i].second,h,w);
	cout<<ans<<"\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cout<<fixed<<setprecision(10);
  int ts = 1;
  //cin >> ts;
  rrep(ti,ts) {
    cases++;
    Solver solver;
    solver.solve();
  }
  return 0;
}

// E(mi) - EV of money of ith shark
// summation of expected value of each shark
// E(m1+m2+m3+m4+m4...+mn) = E(mi) i = 1 to i = n
