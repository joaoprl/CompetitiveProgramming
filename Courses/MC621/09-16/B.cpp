// B. Hiperprimos

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define N 2000001

bool isPrime(vector<int> primes, int n){
  for(int i = 0;  i < primes.size() && primes[i] <= n; i++){
    if(primes[i] == n)
      return true;
  }
  return false;
}

void computePrimes(vector<int> &primes, int n){
  int *arr = new int[n];
  for(int i = 0; i < n; i++)
    arr[i] = 0;

    primes.push_back(2);
  for(int i = 3; i < n; i += 2){
    if(arr[i] == 0){
      primes.push_back(i);
      for(int m = i; m < n; m += i)
        arr[m] = 1;
    }
  }
  
  delete[] arr;
}

int main(){
  int n;
  int *hiperPrimes = new int[N];
  vector<int> primes;

  computePrimes(primes, N);

  long long prime = 0;

  for(int i = 0; i < primes.size(); i++){
    hiperPrimes[primes[i]] = 1;
    long long v = 0;
    for(int m = 2; (v = pow(primes[i], m)) < N && v > 0; m += 2){
      if(isPrime(primes, m + 1))
        hiperPrimes[v] = 1;
    }
  }

  for(int i = 0, k = 0; i < N; i++){
    if(hiperPrimes[i] == 1)
      k++;
    hiperPrimes[i] = k;
  }

  while(cin >> n)
    cout << hiperPrimes[n] << "\n";

  return 0;
}
