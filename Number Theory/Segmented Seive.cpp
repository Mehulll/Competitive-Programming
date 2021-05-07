#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
vector<int> req;
vi primes;
int prime[100001];
 
void sieve(int maxN)
{
  vi ar(maxN + 1 , 0);
  ar[1] = 1;
  
  for(int i=2;i<=maxN;i++)
  if(ar[i] == 0)
  {
    for(int j=2*i;j<=maxN;j+=i)
    ar[j] = 1;
  }
  
  REP(i , maxN)
  if(ar[i] == 0)
  primes.pb(i);
}
 
void init(int L , int R)
{
  if(L == 1) L++;
  
  int maxN = R - L + 1;
  vi ar(maxN , 0);
  
  for(lli p : primes)
  if(p*p <= R)
  {
    int i = (L / p) * p;
    if(i < L) i += p;
    
    for(;i<=R;i+=p)
    {
      if(i != p)
      ar[i-L] = 1;
    }
  }
  
  for(int i=0;i<maxN;i++)
  if(ar[i] == 0)
    req.push_back(L+i);
}
 
int main()
{
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve(100000);
  int t , L , R;
  cin>>t;
  
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++)
      cin >> a[i];
    L = min_element(a.begin(),a.end())-a.begin();
    R = a[L]+n*50;

    init(a[L]+1 , R);
    vector<pair<int,int>> m1 , m2;
    int l = 0;
    for(int i = L+1 ; i < n ; i++){
      m1.push_back({L+1,i+1});
      m2.push_back({a[L],req[l]});
      l++;
    }
    for(int i = L-1 ; i >= 0 ; i--){
      m1.push_back({L+1,i+1});
      m2.push_back({a[L],req[l]});
      l++;
    }
    cout<<m1.size()<<"\n";
    for(int i = 0 ; i < (int)m1.size() ; i++){
      cout<<m1[i].first<<" "<<m1[i].second<<" "<<m2[i].first<<" "<<m2[i].second<<"\n";
    }
    req.clear();
  }
}
