
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int last_prime(int n){
  if(n == 2)
    return 2;

  vector<int> primes;

  int root = pow(n, 0.5) + 2;
  bool *rout = new bool[root];
  for(int i = 0; i < root; i++)
    rout[i] = true;

  for(int i = 2; i < root; i++){
    if(rout[i]){
      for(int j = 2 * i; j < root; j += i)
        rout[j] = false;
      primes.push_back(i);
    }
  }

  bool isprime;
  if(n % 2 == 0)
    n--;
  for(int i = n; i >= 0; i -= 2){
    isprime = true;
    for(int j = 0; j < primes.size() && isprime && primes[j] <= pow(i, 0.5); j++){
      if(i % primes[j] == 0)
        isprime = false;
    }
    if(isprime)
      return i;
  }
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  cout << last_prime(n) << endl;;

  return 0;
}
