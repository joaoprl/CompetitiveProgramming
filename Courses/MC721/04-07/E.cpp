
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int d, f, g;

  while(cin >> d >> f >> g){
    if(12 * 12 * g * g >= (12 * 12 + d * d) * f * f)
      cout << "S\n";
    else
      cout << "N\n";
  }

  return 0;
}
