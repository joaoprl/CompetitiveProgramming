// B. Rectangles

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

#define MAXSIZE 20

int main()
{
  int t;
  cin >> t;
  
  while(t--){
    int n, x, y, minX, minY, maxX, maxY;
    cin >> n;

    minX = minY = INT_MAX;
    maxX = maxY = INT_MIN;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < 4; j++){
	cin >> x >> y;

	if(x < minX)
	  minX = x;
	if(x > maxX)
	  maxX = x;
	if(y < minY)
	  minY = y;
	if(y > maxY)
	  maxY = y;
      }
    }

    cout << (maxX - minX) * (maxY - minY) << "\n";

  }
  return 0;
}
