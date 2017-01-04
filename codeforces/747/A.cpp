// A. Display Size

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int sq = pow(n, 0.5) + 1;
  int a = 1, b = n;
  for(int i = 1; i <= sq; i++){
    if(n % i == 0){
      if(n / i - i < b - a){
        b = n / i;
        a = i;
      }
    }
  }

  cout << min(a, b) << " " << max(a, b) << endl;

  return 0;
}
