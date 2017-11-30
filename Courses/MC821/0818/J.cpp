
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int x, y, a, b;
  cin >> x >> y >> a >> b;

  cout << (b - a) / (x * y) + (a % (x * y) + (b - a)) % (x * y) == 0 + (a % (x * y))<< endl;

  return 0;
}
