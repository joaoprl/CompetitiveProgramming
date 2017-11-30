// E. Pasha and Stick

#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  if(n % 2 == 0)
    cout << (n / 2 - 1) / 2 << "\n";
  else
    cout << "0\n";

  return 0;
}
