#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n , k;
	cin >> n >> k;
	vector<int> value;
	int ans = 0;
	for(int i = 0 ; i < k ; i++){
		int x;
		cin >> x;
		value.push_back(x);
	}
	for(int i = 1 ; i <(1 << k) ; i++){
		int count = 0;
		int l = n;
		for(int j = 0 ; j < k ; j++){
			if(i & (1 << j)){
				l/=value[j];
				count++;
			}
		}
		if(count%2)
			ans+=l;
		else
			ans-=l;
	}
	cout<<ans<<"\n";
}
