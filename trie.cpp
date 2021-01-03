struct trie{
	bool isend;
	unordered_map<char,trie*> mp;
	trie(){
		isend = false;
	}
};
 
struct trie *root;
 
int flag = true;
 
void insert(string str){
	struct trie* cur = root;
	for(int i = 0 ; i < (int)str.size() ; i++){
		if(cur->isend == true)
			flag = false;
		if(!cur->mp.count(str[i]))
			cur->mp[str[i]] = new trie;
		cur = cur->mp[str[i]];
	}
	cur->isend = true;
	for(int i = 0 ; i < 10 ; i++)
		if(cur->mp.count(i+'0'))
			flag = false;
}
