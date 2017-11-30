
#include <vector>
#include <cstring>

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

