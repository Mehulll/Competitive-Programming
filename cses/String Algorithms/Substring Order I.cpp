#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define ll long long
#define int ll
const int N = 2e5 + 5;
const int INF = 1e9+1;
const int mod = 1e9+7;


ll add(ll x, ll y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

ll sub(ll x, ll y) {
  x -= y;
  if (x < 0) return x + mod;
  return x;
}

ll mult(ll x, ll y) {
  return (x * y) % mod;
}

int power(int x,int n,int M){   
    if(n < 0)
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

void counting_sort(vector<int> &p , vector<int> &c){
    int n = p.size();
    
    vector<int> cnt(n);
    for(auto x : c){
        cnt[x]++;
    }
    vector<int> pnew(n);
    vector<int> pos(n);
    pos[0] = 0;
    for(int i = 1 ; i < n ; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x : p){
        int i = c[x];
        pnew[pos[i]] = x;
        pos[i]++;
    }
    p = pnew;
    
}

vector<int> longest_common_prefix(vector<int>& p , vector<int>& c , string& s){
    int n = s.size();
    vector<int> lc(n);
    int k = 0;
    for(int i = 0 ; i < n-1 ; i++){
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k] == s[j+k])
            k++;
        lc[pi] = k;
        k = max(k-1,0LL);
    }
    return lc;
}

pair<vector<int>,vector<int>> suffix_array(string& s){
    s+='#';
    int n = s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i = 0 ; i < n ; i++)
            a[i] = {s[i],i};
        sort(a.begin(),a.end());
        
        for(int i = 0 ; i < n ; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1 ; i < n ; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    int k = 0;
    while((1 << k) < n){
        for(int i = 0 ; i < n ; i++){
            p[i] = (p[i] - (1 << k)+n)%n;
        }
        counting_sort(p,c);
        vector<int> cnew(n);
        cnew[p[0]] = 0;
        for(int i = 1 ; i < n ; i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+(1 << k))%n]};
            pair<int,int> now = {c[p[i]],c[(p[i]+(1 << k))%n]};
            if(now == prev){
                cnew[p[i]] = cnew[p[i-1]];
            }
            else{
                cnew[p[i]] = cnew[p[i-1]] + 1;
            }
        }
        c = cnew;
        k++;
    }
    return {p,c};
}

int cases  = 0;
struct Solver{
    void solve(){
      string str;
      cin >> str;
      int k;
      cin >> k;
      int n = str.size();
      pair<vector<int>,vector<int>> l = suffix_array(str);
      vector<int> p = l.first , c = l.second;
      vector<int> lcp = longest_common_prefix(p,c,str);
      int total = 0;
      n++;
      for(int i = 1 ; i < n ; i++){
        int prev = n-p[i]-lcp[i]-1;
        if(prev+total < k)
          total+=prev;
        else{
            string ans = "";
          int j = 0;
          while(j != lcp[i]){
            ans += str[p[i]+j];
            j++;
          }
          while(total != k){
            ans += str[p[i]+j];
            total++;
            j++;
          }
          cout<<ans<<"\n";
          return;
          }

      }
  }
};

int32_t main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed<<setprecision(10);
     int ts = 1;
    rrep(ti,ts) {
        cases++;
        Solver solver;
        solver.solve();
    }
    return 0;
}

// a aa aab - 3
// a aa aac aacb aacba aacbaab
// a
