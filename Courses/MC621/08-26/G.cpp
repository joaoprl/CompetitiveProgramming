// G. Bicycle Race

#include <iostream>

using namespace std;

int main(){
  int n, x1, y1, x2, y2, x3, y3, d = 0;
  cin >> n;

  cin >> x1 >> y1 >> x2 >> y2;
  n--;
  
  while(n--){
    cin >> x3 >> y3;

    if((x1 == x2 && y1 < y2 && x2 > x3) || // north to west
       (x1 > x2 && y1 == y2 && y2 > y3) || // west to south
       (x1 == x2 && y1 > y2 && x3 > x2) || // south to east
       (x1 < x2 && y1 == y2 && y3 > y2)) // east to north
      d++;

    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;    
  }

  cout << d << "\n";
  
  return 0;
}
