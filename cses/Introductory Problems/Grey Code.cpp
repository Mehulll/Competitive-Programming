void greyCode(int n){
	for(int i = 0 ; i < (1 << n) ; i++){
		int val = (i ^ (i >> 1));
		bitset<32> r(val);
		string s = r.to_string();
		cout<<s.substr(32-n)<<"\n";
	}
}
