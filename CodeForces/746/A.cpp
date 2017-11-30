// A. Compote

#include <iostream>
#define min3(x, y, z) min(x, min(y, z))

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;

  cout << min3(a, b / 2, c / 4) * 7 << endl;

  return 0;
}
