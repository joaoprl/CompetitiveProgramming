// I. Game of chocolate

#include <iostream>
#include <cstdio>
#include <vector>

#define N 3000000

using namespace std;

void computePrimes(int n, vector<int> &v){
  int *arr = new int[n];
  for(int i = 0; i < n; i++)
    arr[i] = 0;

  v.push_back(2);
  for(int i = 3; i < n; i += 2){
    if(arr[i] == 0){
      for(int j = i; j < n; j += 2 * i)
        arr[j] = 1;
      v.push_back(i);
    }
  }

  delete[] arr;
}

int main(){
  int t;
  long long x1, y1, x2, y2;
  cin >> t;
  long long q, k;

  vector<int> primes;
  computePrimes(N, primes);

  for(int c = 1; c <= t; c++){
    cin >> x1 >> y1 >> x2 >> y2;
    q = x1 * (x2 + 1) + y1 * (y2 + 1);
    k = (y1 + x1) * (y2 + x2 + 1);
    if(q != 0){
      for(int i = 0; i < primes.size(); i++){
        while(q % primes[i] == 0 && k % primes[i] == 0){
          q = q / primes[i];
          k = k / primes[i];
        }

      }
      printf("Case %d: %lld/%lld\n", c, q, k);
    }
    else
      printf("Case %d: 0\n", c);
  }

  return 0;
}
