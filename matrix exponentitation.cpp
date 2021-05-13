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
//typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
//typedef vector<P> vp;
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

//#define int ll
#define lld long double

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

struct P {
	long long x , y;
	void read(){
		cin >> x >> y;
	}
	P operator -(const P& b) const {
		return P{x - b.x , y - b.y};
	}
	void operator -=(const P& b){
		x-=b.x;
		y-=b.y;
	}
	long long operator *(const P& b) const {
		return (long long) x * b.y - (long long) y * b.x;
	}
	long long triangle(const P& b , const P& c) const {
		return (b - *this) * (c - *this);
	}
	bool operator <(const P& b) const {
		return make_pair(x,y) < make_pair(b.x,b.y);
	}
};
const ll M2 = (ll)mod*mod;

#define mat vector<vector<ll>>

mat cn(int n , int m){
	return vector<vector<ll>>(n,vector<ll>(m));
}
 
mat mult(mat &a , mat &b){
	mat c = cn((int)a.size(),(int)b[0].size());
	for(int i = 0 ; i < (int)a.size() ; i++){
		for(int k = 0 ; k < (int) b.size() ; k++){
			for(int j = 0 ; j < (int)b[0].size() ; j++){
				c[i][j] += (ll)a[i][k]*b[k][j];
				if(c[i][j] >= M2)
					c[i][j]-=M2;
			}
		}
	}
	for(int i = 0 ; i < (int)a.size() ; i++){
		for(int j = 0 ; j < (int) b[0].size() ; j++){
			c[i][j]%=mod;
		}
	}
	return c;
}

struct Solver {
 void solve(){
	 int n;
	 cin >> n;
	 mat ans = cn(4,4);
	 for(int i = 0 ; i < 4 ; i++){
		 for(int j = 0 ; j < 4 ; j++){
			 if(i == j){
				 ans[i][i] = 0;
			 }
			 else{
				 ans[i][j] = 1;
			 }
		 }
	 }
	 mat b = cn(4,4);
	 for(int i = 0 ; i < 4 ; i++){
		 b[i][i] = 1;
	 }
	 while(n){
		 if(n&1)
			b = mult(ans,b);
		 ans = mult(ans,ans);
		 n/=2;
	 }
	 cout<<b[0][0]<<"\n"; // bases cases is stored here 
  }
};

int main() {
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
