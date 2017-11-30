
#include <iostream>
#include <iomanip>

#define min3(x, y, z) min(x, min(y, z))

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  double av = 0;
  double acc = 0;
  double *a = new double[n];
  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < k; i++)
    acc += a[i];

  av = acc;
  for(int i = k; i < n; i++){
    acc = acc + a[i] - a[i - k];
    av += acc;
  }

  cout << fixed << setprecision(10) << av / (n - k + 1) << endl;

  return 0;
}
