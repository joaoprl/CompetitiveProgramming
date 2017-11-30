// D. RSA

#include <iostream>
#include <cmath>
#include <vector>

#define MAXPRIME 100000

using namespace std;

long long modpow(long long c, long long d, long long n){
  if(d == 1)
    return c;
  if(d == 0)
    return 1;

  return (modpow((c * c) % n, d / 2, n) * modpow(c, d % 2, n)) % n;
}

void compute_primes(vector<long long> &primes){
  primes.push_back(2);

  bool *arr = new bool[MAXPRIME];
  for(int i = 0; i < MAXPRIME; i++)
    arr[i] = true;
  for(int i = 3; i < MAXPRIME; i += 2){
    if(arr[i] == true){
      primes.push_back(i);
      for(int j = i; j < MAXPRIME; j += 2 * i)
        arr[j] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  vector<long long> primes;

  long long n, e, c;
  cin >> n >> e >> c;

  compute_primes(primes);

  long long p, q, tot;
  for(int i = 0; i < primes.size(); i++){
    if(n % primes[i] == 0){
      p = primes[i];
      q = n / p;
      tot = (p - 1) * (q - 1);
      break;
    }
  }

  long long tot0 = tot, t, quo;
  long long x = 0, d = 1;

  // multiplicative inverse
  // based on http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
  while(e > 1){
      quo = e / tot;
      t = tot;
      tot = e % tot;
      e = t;
      t = x;
      x = d - quo * x;
      d = t;
  }
  if (d < 0)
     d += tot0;

  cout << modpow(c, d, n) << endl;

  return 0;
}
