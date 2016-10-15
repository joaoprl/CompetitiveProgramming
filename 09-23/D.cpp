// D. Calculating Function

#include <iostream>

using namespace std;

int main(){
  long long n;
  cin >> n;

  if(n % 2 == 0)
    cout << n / 2 << "\n";
  else
    cout << n / 2 - n << "\n";

  return 0;
}
