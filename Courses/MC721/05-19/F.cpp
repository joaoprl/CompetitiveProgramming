
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define N 100

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  double *mi = new double[N];
  while(cin >> n){
    double sum = 0;
    for(int i = 0; i < n; i++)
      cin >> mi[i];

    sort(mi, mi + n);
    double mid = mi[n / 2];

    sum = 0;
    for(int i = 0; i < n; i++){
      sum += abs(mid - mi[i]);
    }

    cout << fixed << setprecision(2) << sum << endl;

  }

  return 0;
}
