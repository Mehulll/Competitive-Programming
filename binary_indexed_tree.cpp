template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  void replace(int i , T v){
    add(i,v-sum(i,i+1));
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

BIT<int> bit(n);
// use zero based index in every function its ++ in function
// one index at 0 query bit.sum(0,1)


template<typename T>
struct BIT {
    int n;
    vector<T> d;

    BIT(int n=0): n(n), d(n+1,0) {}

    // build from array in O(n)
    BIT(const vector<T>& a) {
        n = a.size();
        d.assign(n+1,0);

        for(int i = 1; i <= n; i++) {
            d[i] += a[i-1];
            int j = i + (i & -i);
            if(j <= n)
                d[j] += d[i];
        }
    }

    void add(int i, T x=1) {
        for(i++; i <= n; i += i&-i)
            d[i] += x;
    }

    void replace(int i, T v) {
        add(i, v - sum(i,i+1));
    }

    T sum(int i) {
        T x = 0;
        for(i++; i > 0; i -= i&-i)
            x += d[i];
        return x;
    }

    T sum(int l, int r) {
        return sum(r-1) - (l ? sum(l-1) : 0);
    }
};

// Insert the array
// vector<int> a = {4,3,2,1};
//BIT<int> bit(a);
