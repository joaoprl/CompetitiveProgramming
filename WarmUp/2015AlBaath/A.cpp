// A. Traffic Lights

#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int x, g, y, r;
    cin >> x >> g >> y >> r;

    x %= g + y + r;

    if(x < g)
      cout << "GREEN\n";
    else if(x < g + y)
      cout << "YELLOW\n";
    else
      cout << "RED\n";

    
  }
  return 0;
}
