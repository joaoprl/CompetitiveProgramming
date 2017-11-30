// B. Alyona and flowers

#include <iostream>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int *arr = new int[n + 1];
  arr[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }

  int happiness = 0, l, r;
  for(int i = 0; i < m; i++){
    cin >> l >> r;
    if(arr[r] - arr[l - 1] > 0)
      happiness += arr[r] - arr[l - 1];
  }

  cout << happiness << endl;

  return 0;
}
