
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define N 10001

using namespace std;

double area(double a, double b, double c){
  if(a + b > c && a + c > b && b + c > a){
    double p = (a + b + c) / 2.0;
    return pow(p * (p - a) * (p - b) * (p - c), 0.5);
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  double * s = new double[N];
  while(t--){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
      cin >> s[i];

    sort(s, s + n);

    double a = 0;
    for(int i = 1; i < n; i++){
      double *it = lower_bound(s + i + 1, s + n, s[i] + s[i - 1]);

      if(it - s - 1 > i){
        // cout << i << " " << i - 1 << " " << it - s - 1 << endl;
        a = max(a, area(s[i], s[i - 1], *(it - 1)));
      }
    }

    cout << fixed << setprecision(2) << a << endl;
  }

  return 0;
}
