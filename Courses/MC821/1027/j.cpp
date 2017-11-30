
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  double a, b, c;
  while(cin >> a >> b >> c){
    double s = (a + b + c) / 2;
    double ar = 4 * sqrt(s) * sqrt(s - a) * sqrt(s - b) * sqrt(s - c) / 3;
    if(s - a <= 0 || s - b <= 0 || s - c <= 0)
      	cout << "-1.000" << endl;
    else
    	cout << fixed << setprecision(3) << ar << endl;
  }
  return 0;
}
