// I. Game of Ones

#include <iostream>

using namespace std;

int main(){
  int t, n;
  long long k;
  cin >> t;
  while(t--){
    cin >> n;
    if(n >= 2){
      k = (long long)(1LL << (n - 2));
      cout << 2 * k << " " << k * (n - 1) + 2 * k << "\n";
    }
    else cout << "1 1\n";
  }
  return 0;
}
