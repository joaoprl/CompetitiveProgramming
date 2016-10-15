// F. Linearian Colony

#include <iostream>

using namespace std;

int main(){
  int y;
  long long p;
  cin >> y >> p;

  bool b = false;
  while(y--){
    if(p % 2 == 0)
      b = !b;
    p = p / 2;
  }

  if(b)
    cout << "blue\n";
  else
    cout << "red\n";

  return 0;
}
