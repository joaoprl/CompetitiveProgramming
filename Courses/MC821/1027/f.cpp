
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = acos(-1);
const double EPS = 1e-10;

int main(){
  ios::sync_with_stdio(false);
  double l, dt, c;
  while(cin >> l >> dt >> c && (l >= 0 || dt >= 0 || c >= 0)){
    double ll = (1 + dt * c) * l;
    double fl = 0, ce = pi;

    while(abs(fl - ce) > EPS){
      double alpha = (fl + ce) / 2;

      if(sin(alpha) > l * alpha / ll)
        fl = alpha;
      else
        ce = alpha;
    }

    if(fl < EPS)
      cout << "0.000" << endl;
    else{
      double rad = ll / (2 * fl);

      cout << fixed << setprecision(3) << rad - sqrt(rad * rad - l * l / 4) << endl;
    }
  }
  return 0;
}
