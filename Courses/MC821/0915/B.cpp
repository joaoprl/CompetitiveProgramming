// C. Almost Prime Numbers

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

#define N 1000000000000
#define SQN 1000000

typedef long long ll;

using namespace std;

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

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> pr = primes(SQN);

  vector<ll> numbers;
  for(int i = 0; i < pr.size(); i++){
    ll p = pr[i];
    for(ll t = p * p; t <= N; t *= p){
      numbers.push_back(t);
    }
  }

  sort(numbers.begin(), numbers.end());

  for(int t = 0; t < n; t++){
    ll a, b;
    cin >> a >> b;

    vector<ll>::iterator lo, hi;
    lo = lower_bound(numbers.begin(), numbers.end(), a);
    hi = upper_bound(numbers.begin(), numbers.end(), b);

    cout << hi - lo << endl;
  }

  return 0;
}
