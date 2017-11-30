
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int x, y;
  cin >> x >> y;
  int c = y / (y - x);
  if(y % (y - x) != 0)
    c++;
  cout << c << endl;

  return 0;
}
