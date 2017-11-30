// G. Count Mix Strings

#include <iostream>
#include <cstdio>
#include <cmath>

#define MOD (int)(1e9 + 7)

using namespace std;

int fast_pow(long long base, long long n, long long M)
{
  if(n == 0)
    return 1;
  if(n == 1)
    return base;
  
  long long halfn = fast_pow(base, n / 2, M);
  
  if(n % 2 == 0)    
    return (halfn * halfn) % M;
  
  else
    return (((halfn * halfn) % M) * base) % M;
}

int findMMI(int n, int M)
{
  return fast_pow(n, M-2, M);
}

long long combinatory(int n, int m){

  if(2 * m < n)
    m = n - m;
  if(n == m)
    return 1;
  
  long long v1 = 1;

  for(int i = m + 1; i <= n; i++){    
    v1 *= i;
    v1 %= MOD;
  }

  long long v2 = 1;
  for(int i = 2; i <= n - m; i++){
    v2 *= i;
    v1 %= MOD;
  }

    
  return (v1 * findMMI(v2, MOD)) % MOD;
}

int main()
{
  int t;
  cin >> t;
  
  while(t--){
    
    int n, m;
    cin >> n >> m;

    cout << combinatory(n, m) << "\n";
    
  }
  return 0;
}
