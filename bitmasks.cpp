for(int i = 0 ; i < (1 << n) ; i++){
  for(int j = 0 ; j < n ; j++){
    if(i & (1 << j)){
      // something 
    }
    else{
      // something
    }
  }
}

struct Solver {
 void solve(){
   int n; cin >> n;
    int ax = 1023 , in = 0;
    for(int i = 0 ; i < n ; i++){
      char x; int num;
      cin >> x >> num;
      if(x == '|'){
        ax |= num;
        in |= num;
      }
      else if(x == '&'){
        ax &= num;
        in &= num;
      }
      else{
        ax ^= num;
        in ^= num;
      }
    }
    int xornum = ~ax;
    int ornum = ~(ax ^ in);
    xornum &= 1023;
    ornum &= 1023;
    cout<<2<<"\n";
    cout<<"| "<<ornum<<"\n";
    cout<<"^ "<<xornum<<"\n";
  }
};
