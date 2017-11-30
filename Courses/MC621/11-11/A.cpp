// A. Hit the Target!

#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int minD = 1, minH = 0, maxD = 1, maxH = 10000;
  int d, a, b;

  n++;
  while(n--){
    cin >> d >> a >> b;
    if(minH * d < a * minD){
      minH = a;
      minD = d;
    }
    if(maxH * d > b * maxD){
      maxH = b;
      maxD = d;
    }
  }

  if(maxH * minD >= minH * maxD)
    cout << "Y\n";
  else
    cout << "N\n";

  return 0;
}
