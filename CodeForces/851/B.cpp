// B. Arpa and an exam about geometry

#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  long long x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == (y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2) &&
    (y3 - y2) * (x2 - x1) != (y2 - y1) * (x3 - x2))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
