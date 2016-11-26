// B. Anton and Digits

#include <iostream>

#define min3(x, y, z) min(x, min(y, z))

using namespace std;

int main(){
  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;

  int num256 = min3(k2, k5, k6);
  cout << num256 * 256 + min(k2 - num256, k3) * 32 << endl;

  return 0;
}
