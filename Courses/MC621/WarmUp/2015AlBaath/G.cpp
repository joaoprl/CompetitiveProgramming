// G. Square Spiral Search

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for(int i = 0; i < t; i++){
    int x, y, ma, mi;
    cin >> x >> y;
    
    ma = max(abs(x), abs(y));
    mi = min(abs(x), abs(y));

    if(ma == 0){
      cout << "0\n";
      continue;
    }

    long long result = pow((2 * ma - 1), 2);
    cout << "result: " << result << "\n";
    
    if(x == ma && y != -ma)
      result += 1 * ma + y - 1;
    else if(y == ma)
      result += 2 * ma - 1 - x + 2;
    else if(x == -ma)
      result += 4 * ma - 1 - y + 2;
    else if(y == -ma)
      result += 6 * ma - 1 + x + 2;
	    
    cout << result << "\n";
  }
  return 0;
}
