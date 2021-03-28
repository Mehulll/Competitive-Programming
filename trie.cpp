#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct trie{
	bool isend;
	unordered_map<char,trie*> mp;
	trie(){
		isend = false;
	}
};

struct trie* root;

void insert(string str){
	struct trie* cur = root;
	for(char ch : str){
		if(!cur->mp.count(ch))
			cur->mp[ch] = new trie;
		cur = cur->mp[ch];
	}
	cur->isend = true;
}

bool search(string str){
	struct trie* cur = root;
	for(char ch : str){
		if(!cur->mp.count(ch))
			return false;
		cur = cur->mp[ch];
	}
	return cur->isend;
}

void test(){
	int n;
	cin >> n;
	root = new trie;
	while(n--){
		string str;
		cin >> str;
		insert(str);
	}
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		cout<<search(str)<<"\n";
	}
}

int main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  // cin >> T;
  while(T--){
    test();
  }
}

// every tree is a valid splay tree
// 
