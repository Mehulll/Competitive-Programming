#include <bits/stdc++.h>
using namespace std;
 
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
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	s+='$';
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
	
	vector<int> lcp(n);
	k = 0;
	for(int i = 0 ; i < n -1 ; i++){
		int pi = c[i];
		int j = p[pi-1];
		// lcp[i] = lcp(s[i..j],s[j])
		while(s[i+k] == s[j+k]) k++;
		lcp[pi] = k;
		k = max(k-1,0);
	}
	//for(int i = 0 ; i < n ; i++){
		//cout<<lcp[i]<<" "<<p[i]<<" "<<s.substr(p[i],n-p[i])<<"\n";
	//}
	
	
	long long  sum = 0;
	for(int i = 1 ; i < n ; i++){
		sum+=n-p[i]-lcp[i]-1;
	}
	cout<<sum;
	
}
