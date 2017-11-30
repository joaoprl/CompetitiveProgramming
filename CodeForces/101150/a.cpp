
// A. Sum of Consecutive Prime Numbers

#include <iostream>
#include <vector>

#define M 10000

using namespace std;

vector<int> primes(int n){
  vector<bool> prB(n + 1, true);
  vector<int> prs;
  prB[0] = prB[1] = prB[2] = false;
  prs.push_back(2);

  for(int i = 3; i < prB.size(); i += 2){
    if(prB[i]){
      prs.push_back(i);
      for(int k = 3 * i; k < prB.size(); k += 2 * i)
          prB[k] = false;
    }
  }

  return prs;
}

int main(){
  ios::sync_with_stdio(false);
  vector<int> prs = primes(M);
  vector<int> count(M + 1, 0);

  for(int i = 1; i < prs.size(); i++)
    prs[i] += prs[i - 1];

  for(int i = 0; i < prs.size(); i++){
    if(prs[i] <= M)
      count[prs[i]]++;
    for(int j = i; j < prs.size(); j++){
      if(prs[j] - prs[i] <= M)
        count[prs[j] - prs[i]]++;
    }
  }

  int n;
  while(cin >> n && n != 0){
    cout << count[n] << endl;
  }

  return 0;
}
