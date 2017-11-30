// G. Economy Game

#include <iostream>

using namespace std;

int main(){
  int n, a, b;
  cin >> n;

  for(int a = 0; a <= n; a += 1234567){
    for(int b = 0; a + b <= n; b += 123456){
      if((n - (a + b)) % 1234 == 0){
          cout << "YES\n";
          return 0;
      }
    }
  }
  cout << "NO\n";

  return 0;
}
