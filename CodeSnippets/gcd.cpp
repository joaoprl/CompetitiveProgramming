// GCD and BS and primes

// log10 max(a, b)
int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

// log2(|V|)
int binarysearch(const vector<int> &v, int val){
    int lo = 0, hi = v.size() - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(v[mid] >= val)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

vector<int> primes(int n){
  bool p[n + 1];
  memset(p, 0, sizeof(bool) * (n + 1));

  vector<int> pr;
  pr.push_back(2);
  for(int i = 3; i <= n; i += 2){
    if(!p[i]){
      for(int k = i * 2; k <= n; k += i)
        p[k] = true;
      pr.push_back(i);
    }
  }

  return pr;
}

