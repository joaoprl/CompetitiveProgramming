
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  int *a = new int [n];
  int *b = new int [k];

  for(int i = 0; i < n; i++)
    cin >> a[i];
  for(int i = 0; i < k; i++)
    cin >> b[i];
  sort(b, b + k, greater<int>());

  int j = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == 0){
      a[i] = b[j];
      j++;
    }
  }

  bool inc = a[0] <= a[1] && a[n - 2] <= a[n - 1];
  for(int i = 1; i < n - 1; i++){
    if(a[i - 1] >= a[i])
      inc = false;
    if(a[i] >= a[i + 1])
      inc = false;
  }

  if(!inc)
    cout << "Yes\n";
  else
    cout << "No\n";


  return 0;
}
