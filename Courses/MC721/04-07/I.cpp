
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p, q, r, s, t, u;

double eq(double x){
  const double e = exp(1);
  return p * pow(e, -x) + q * sin(x) + r * cos(x) +
    s * tan(x) + t * x * x + u;
}

bool compute(double a, double b, double &r){
  double eA = eq(a);
  double eB = eq(b);

  if(eA == 0){
    r = a;
    return true;
  }
  if(eB == 0){
    r = b;
    return true;
  }

  if((eA > 0 && eB < 0) || (eA < 0 && eB > 0)){
    if(abs(b - a) < 0.00001){
      r = a;
      return true;
    }

    return compute(a, (a + b) / 2, r) || compute((a + b) / 2, b, r);
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);

  double x, calc;
  double curr, xs;
  while(cin >> p >> q >> r >> s >> t >> u){
    double r;


    if(!compute(0, 1, r))
      cout << "No solution\n";

    else
      cout << fixed << setprecision(4) << r << endl;

  }

  return 0;
}
