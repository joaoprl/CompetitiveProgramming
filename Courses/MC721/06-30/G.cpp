
#include <iostream>
#include <iomanip>

#define ERR 0.0000001

using namespace std;

double abs(double a){
  if(a < 0)
    return -a;
  return a;
}

int main(){
  ios::sync_with_stdio(false);

  int n;
  double a;

  double *ar = new double[100010];

  while(cin >> n >> a && (n != 0 || a != 0)){
    for(int i = 0; i < n; i++)
      cin >> ar[i];

    double lo = -100;
    double hi = 2e9;
    double re = (lo + hi) / 2;
    double cur = 0;

    while(abs(cur - a) > ERR){
      if(hi < 0 || lo > 1e9){
        break;
      }

      re = (lo + hi) / 2;
      cur = 0;
      for(int i = 0; i < n; i++)
        cur += max(0.0, (double)(ar[i] - re));

      if(abs(cur - a) < ERR){
        break;
      }
      if(cur < a)
        hi = re;
      else
        lo = re;
      }

      if(abs(cur - a) < ERR){
        if(re < ERR)
          cout << ":D" << endl;
        else
          cout << fixed << setprecision(4) << re << endl;
      }else{
          cout << "-.-" << endl;
      }
  }

  return 0;
}
