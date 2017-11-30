
#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int F(int n){
  int a = 0, b = 1;

  for(int i = 0; i < n; i++){
    a = (a + b) % MOD;
    swap(a, b);
  }

  return a;
}

int G(int n){
  int r = 0;
  for(int i = 1; i <= n; i++)
    r = (r + F(4 * i - 1)) % MOD;
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  int n = 0;
  for(int i = 0; i < 10; i++){
    cout << i << " " << G(i) << endl;
  }
  return 0;
}
