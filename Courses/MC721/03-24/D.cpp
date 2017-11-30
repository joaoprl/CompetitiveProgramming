
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;

  int root = (int)(pow(n, 0.5));
  bool isPrime = true;
  for(int i = 2; i <= root; i++){
    if(n % i == 0){
      isPrime = false;
      break;
    }
  }

  if(isPrime && n >= 2)
    cout << "sim\n";
  else
    cout << "nao\n";


  return 0;
}
