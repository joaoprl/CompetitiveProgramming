// C. Eefun is not so Fun

#include <iostream>
#include <cmath>
#include <cstdlib>

#define MOD ((long long)1e9+7)

using namespace std;

unsigned long long pot(unsigned long long sq, unsigned long long k, unsigned long long mod){
  if(k == 0)
    return (unsigned long long)1;
  if(k == 1)
    return sq;

  unsigned long long value = 1, f;
  f = pot(sq, k / 2, mod);
  value = (f * f) % mod;
  value = value * pot(sq, k % 2, mod);
  value = value % mod;

  return value;
}

int main(){
  ios::sync_with_stdio(false);
  unsigned long long n, v;
  cin >> n;

  v = 1;
  if(n > 1){
    if(n % 3 == 0){
      v = pot(3, n / 3, MOD);
    }
    else if(n % 3 == 1){
      v = pot(3, n / 3 - 1, MOD);
      v = (2 * v) % MOD;
      v = (2 * v) % MOD;
    }
    else{
      v = pot(3, n / 3, MOD);
      v = (2 * v) % MOD;
    }
  }

  cout << v << endl;

  return 0;
}
