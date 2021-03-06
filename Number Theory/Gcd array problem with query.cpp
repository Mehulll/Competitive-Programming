https://codeforces.com/problemset/problem/939/D
#include <bits/stdc++.h>
#define fi first
#define se second
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
// typedef vector<ll> vl;
typedef vector<P> vp;
// typedef vector<T> vt;
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
int powr(int a, int b){
        int res = 1;
        while(b){
                if(b&1){
                        res *= a;
                }
                res %= mod;
                a *= a;
                a %= mod;
                b /= 2;
        }
        return res%mod;
}

struct Solver {
  void solve() {
    // input 
        int n , q;
        cin >> n >> q;
        vector<map<int,int>> vl(n);
        int ans = 1;
        map<int,set<pair<int,int>>> mp;
        for(int i = 0 ; i < n ; i++){
            int x;
            cin >> x;
            int lt = sqrt(x);
            int j = 2;
            while(j <= x && j <= lt){
                while(x%j == 0){
                    x/=j;
                    vl[i][j]++;
                }
                j++;
            }
            if(x > 1)
                vl[i][x]++;
            for(auto x : vl[i]){
                mp[x.first].insert({x.second,i});
            }
        }
        for(auto x : mp){
            if((int)x.second.size() == n){
                ans *= powr(x.first,((*(x.second).begin())).first);
            }
        }
        while(q--){
            map<int,int> mpp;
            int i , x;
            cin >> i >> x;
            i--;
            int j = 2;
            int lt = sqrt(x);
            while(j <= x && j <= lt){
                while(x%j == 0){
                    x/=j;
                    mpp[j]++;
                }
                j++;
            }
            if(x > 1)
                mpp[x]++;
            for(auto x : mpp){
                int r = vl[i][x.first];
                int last = 0;
                if((int)mp[x.first].size() == n){
                    last = (*(mp[x.first].begin())).first;
                }
                if(r > 0)
                    mp[x.first].erase({r,i});
                vl[i][x.first] += x.second;
                r = vl[i][x.first];
                mp[x.first].insert({r,i});
                if((int)mp[x.first].size() == n){
                    ans *= powr(x.first , (*(mp[x.first].begin())).first-last);
                    ans%=mod;
                }
                last = (*mp[x.first].begin()).first;
            }
            cout<<ans<<"\n";
        }
    }
};

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
  int ts = 1;
  // cin >> ts;
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
