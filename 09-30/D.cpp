// D. Arya Rage

#include <iostream>

#define MOD ((int)(1e9+7))

using namespace std;

int main(){
  int t;
  cin >> t;

  long long g1, g2, gtemp, k, n;
  while(t--){
    cin >> n;

    g1 = 1;
    g2 = 2;

    n %= 1000000008;
    if(n >= 750000010){
      g1 = 515299497;
      g2 = 561976236;
      n -= 750000009;

    }
    else if(n >= 500000006){
      g1 = 1;
      g2 = 500000004;
      n -= 500000004;
    }
    else if(n >= 250000004){
      g1 = 3045123;
      g2 = 540942047;
      n -= 250000001;
    }
    long long k;
    if(n > 0){
      for(k = 1; k < n; k++){
        gtemp = g2;
        g2 = g1 * g2;
        g1 = gtemp;

        g2 %= MOD;
      }
      cout << g2 << "\n";
    }
    else
      cout << "1\n";
  }

  return 0;
}
