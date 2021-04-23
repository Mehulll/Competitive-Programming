#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> calc(vector<int> a){
	int n = a.size();
	vector<int> all;
	all.push_back(0);
	for(int i = 1 ; i < (1 << n) ; i++){
		int sum = 0;
		for(int j = 0 ; j < n ; j++){
			if(i & (1 << j)){
				sum += a[j];
			}
		}
		all.push_back(sum);
	}
	return all;
}

void test(){
	int n , x;
	cin >> n >> x;
	vector<int> a , b;
	for(int i = 0 ; i < n/2 ; i++){
		int l;
		cin >> l;
		a.push_back(l);
	}
	for(int i = n/2 ; i < n ; i++){
		int l;
		cin >> l;
		b.push_back(l);
	}
	a = calc(a);
	b = calc(b);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans = 0;
	for(int i = 0 ; i <(int) a.size() ; i++){
		int p = x-a[i];
		auto l = lower_bound(b.begin(),b.end(),p);
		auto y = upper_bound(b.begin(),b.end(),p) - b.begin();
		if(l == a.end())
			continue;
		else{
			ans += y-(l-b.begin());
		}
	}
	cout<<ans<<"\n";
}

int32_t main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 1;
	cout<<fixed<<setprecision(10);
	// cin >> T;
	while(T--){
		test();
	}
}
