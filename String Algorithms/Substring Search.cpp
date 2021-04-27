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

bool look(string& t , vector<int>& ans , string& str){
	int l = 0;
	int r = ans.size()-1;
	while(l <= r){
		int mid = (l+r)/2;
		//string suf = str.substr(ans[mid]);
		string pre = str.substr(ans[mid],t.size());
		if(pre == t)
			return true;
		if(pre < t)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
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
	p.erase(p.begin());
	s.pop_back();
	int q;
	cin >> q;
	while(q--){
		string t;
		cin >> t;
		if(look(t,p,s)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}

// suffix array is part of data structure

// s = ababba

// suffix of string in lexicographical order

// 6 "
// 5 a
// 0 a b a b b a
// 2 a b b a
// 4 b a
// 1 b a b b a
// 3 b b a

// add special character to string with is lexigraphical is smaller

// s = ababba$


// 6 $
// 5 a$
// 0 a b a b b a $
// 2 a b b a $
// 4 b a $
// 1 b a b b a $
// 3 b b a $

// now make the whole string to same length
// using next character in a cycling string

// 6 $ a b a b b a
// 5 a $ a b a b b
// 0 a b a b b a $
// 2 a b b a $ a b
// 4 b a $ a b a b
// 1 b a b b a $ a
// 3 b b a $ a b a


// we have some cycle shfit 
// we will make the length of string power of 2


// 6 $ a b a b b a $
// 5 a $ a b a b b a
// 0 a b a b b a $ a
// 2 a b b a $ a b a
// 4 b a $ a b a b b
// 1 b a b b a $ a b
// 3 b b a $ a b a b

// iteration k
// we need to sort the string

// base k = 0;

// sorting algortithm - merge sort O(nlogn)
// transition k -> k+1

// time complexity is O(nlogn * logn)

// using radix sort we can reduce complexity
// which work in linear time O(n * logn)

// more optimization 

// each substring is prefix of substring
// O(logn .|p|)
