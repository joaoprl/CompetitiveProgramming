
#include <iostream>
#include <cmath>
#include <iomanip>

#define pi (2 * acos(0))

using namespace std;

int main(){
  ios::sync_with_stdio(false);

  int n;
  double dist, rope, a, b;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> dist >> rope;
    dist /= 2;
    a = rope / 2;
    b = sqrt(a * a - dist * dist);

    cout << fixed << setprecision(3) << pi * a * b << endl;
  }

  return 0;
}
