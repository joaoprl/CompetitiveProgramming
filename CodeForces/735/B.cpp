// B. Urbanization

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void sortInts(int &n1, int &n2){
  int a, b;
  a = n1; b = n2;
  n1 = min(a, b);
  n2 = max(a, b);
}

int main(){
  int n, n1, n2;
  cin >> n >> n1 >> n2;

  int *arr = new int[n];
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  sortInts(n1, n2);

  long long t1 = 0, t2 = 0, total = 0;

  for(int i = n - 1; i >= n - n1; i--)
    t1 += arr[i];

  for(int i = n - n1 - 1; i >= n - n1 - n2; i--)
    t2 += arr[i];

  total = t1 * n2 + t2 * n1;

  double sMean = 0;
  sMean = total / ((double)n1 * n2);
  cout << fixed << setprecision(8) << sMean << endl;

  return 0;
}
